#include <iostream>
#include <fstream>


int *create_array(int count, std::ifstream &infile) {
	int* array = new int[count];
	for (int i = 0; i < count; i++) {
		infile >> array[i];
	}

	return array;
}

void make_one_right(int count, int array[]) {
		
	for (int i = 0; i < count; i++) {
		int tmp;
		if ((i + 1) == count) {
			break;
		}
		tmp = array[i];
		array[i] = array[i + 1];
		array[i + 1] = tmp;
	}
}
void make_one_left(int count, int array[]) {

	for (int i = count - 1; count > 0; i--) {
		int tmp;
		if (i == 0) {
			break;
		}
		tmp = array[i];
		array[i] = array[i - 1];
		array[i - 1] = tmp;
	}
}


void write_out(int count, int array[], std::ofstream &outfile) {
	outfile << count;
	outfile << std::endl;
	for (int i = 0; i < count; i++) {
		outfile << array[i] << ' ';

	}
	outfile << std::endl;
}

int main() {

	std::ifstream infile;
	
	infile.open("in.txt");
	if (infile) {

		std::ofstream outfile;
		outfile.open("out.txt");
		if(outfile){
			int first_count = 0;
			int second_count = 0;
			infile >> first_count;
			int* first_array = create_array(first_count, infile);
			make_one_right(first_count, first_array);
			infile >> second_count;
			int* second_array = create_array(second_count, infile);
			make_one_left(second_count, second_array);
			write_out(second_count, second_array, outfile);
			write_out(first_count, first_array, outfile);
			infile.close();
			outfile.close();
			delete[] first_array;
			delete[] second_array;
			first_array = nullptr;
			second_array = nullptr;

		}
		else {
			std::cout << "output file not found" << std::endl;
		}

	}
	else {
		std::cout << "input file not found" << std::endl;
	}

	return 0;
}


