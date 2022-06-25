// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

/*Workshop #9 Part #2
		  Name        : Rajbeer Sokhi
		  StudentId   : 124969205
		  Email       : rsokhi1@myseneca.ca
		  Section     : NBB
		  Date        : 17th April 2022
*/

#include "process_data.h"

using namespace std;
namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {
	

		ifstream file(filename, ios::in | ios::binary);
		if (!file) {
			throw "Unable to open file";
		}
		file.read((char*)&total_items, sizeof(total_items));
		data = new int[total_items];

		file.read((char*)data, sizeof(int) * total_items);

		file.close();

		std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
			<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
			<< data[total_items - 1] << "]\n";

		
		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads;
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads + 1]{};
		for (int i = 0; i < num_threads + 1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}


	int ProcessData::operator()(std::string filename, double& avg, double& var)
	{
		 
		auto avgFact = bind(computeAvgFactor, placeholders::_1, placeholders::_2, total_items, placeholders::_3);
		vector<thread> adds;
		
		for (int i = 0; i < num_threads; i++) {
			int flag = p_indices[i];
			adds.push_back(thread([=]() {
				avgFact(&data[flag], total_items / num_threads, ref(averages[i]));
				}));
			
		}
		for (auto& a : adds) {
			a.join();
		}

		for (int i = 0; i < num_threads;i++) {
			avg += averages[i];
		}


		auto varFact = bind(computeVarFactor, placeholders::_1, placeholders::_2, total_items, avg, placeholders::_3);
		vector<thread> vars;

		for (int i = 0; i < num_threads; i++) {
			int flag = p_indices[i];
			vars.push_back(thread([=]() {
				varFact(&data[flag], total_items / num_threads, ref(variances[i]));
				}));

		}
		for (auto& a : vars) {
			a.join();
		}

		for (int i = 0; i < num_threads; i++) {
			var += variances[i];
		}



		ofstream file(filename, ios::out | ios::binary);
		if (!file) {
			throw "Unable to open File!";
		}
		file.write((char*)&total_items, sizeof(total_items));
		file.write((char*)data, sizeof(int) * total_items);
		file.close();
		return total_items;
	}

}