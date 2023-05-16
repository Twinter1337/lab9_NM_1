#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

int main(void) {
	double line_pol_def[6][2] = { {1.0, 2.80},
								  {1.0, 2.94},
								  {1.0, 3.20},
								  {1.0, 3.38},
								  {1.0, 3.53},
								  {1.0, 3.75} };
	double square_pol_def[6][3] = { {1.0, 2.80, pow(2.80,2)},
									{1.0, 2.94, pow(2.94,2)},
									{1.0, 3.20, pow(3.20,2)},
									{1.0, 3.38, pow(3.38,2)},
									{1.0, 3.53, pow(3.53,2)},
									{1.0, 3.75, pow(3.75,2)} };
	double cubic_pol_def[6][4] = {  {1.0, 2.80, pow(2.80,2), pow(2.80,3)},
									{1.0, 2.94, pow(2.94,2), pow(2.94,3)},
									{1.0, 3.20, pow(3.20,2), pow(3.20,3)},
									{1.0, 3.38, pow(3.38,2), pow(3.38,3)},
									{1.0, 3.53, pow(3.53,2), pow(3.53,3)},
									{1.0, 3.75, pow(3.75,2), pow(3.75,3)} };
	double free_member_col_def[6][1] = { {3.01},
										 {2.78},
										 {2.52},
										 {2.42},
										 {2.19},
										 {1.95} };
	double** line_pol = MakeMatr(6, 2);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			line_pol[i][j] = line_pol_def[i][j];
		}
	}
	double** square_pol = MakeMatr(6, 3);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			square_pol[i][j] = square_pol_def[i][j];
		}
	}
	double** cubic_pol = MakeMatr(6, 4);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cubic_pol[i][j] = cubic_pol_def[i][j];
		}
	}
	double** free_mem_col = MakeMatr(6, 1);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 1; j++) {
			free_mem_col[i][j] = free_member_col_def[i][j];
		}
	}

	double* line = Find_Coeff(line_pol, free_mem_col, 6, 2);
	for (int i = 0; i < 2; i++) {
		cout << line[i] << " ";
	}

	DelMatr(line_pol, 6);

	cout << endl;
	double* square = Find_Coeff(square_pol, free_mem_col, 6, 3);
	for (int i = 0; i < 3; i++) {
		cout << square[i] << " ";
	}

	DelMatr(square_pol, 6);

	cout << endl;
	double* cubic = Find_Coeff(cubic_pol, free_mem_col, 6, 4);
	for (int i = 0; i < 4; i++) {
		cout << cubic[i] << " ";
	}

	return 0;
}