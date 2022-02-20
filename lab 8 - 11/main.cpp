#define _CRT_SECURE_NO_WARNINGS
#include "IntMatrix.h"
#include "PrintMatrix.h"
#include "exception.h"

void main(int argc, char* argv[]) {
	FILE* file = fopen("log.txt", "w");
	if (file != NULL) {
		//{
		//	//~8
		//	fprintf(file, "Lab 8:\n\n");
		//	//IntMatrix A;
		//	IntMatrix B(3, 4);
		//	//OutputMatrixVer1(A, "Mtx A emty", file);
		//	//OutputMatrixVer1(B, "Mtx B 3 x 4", file);
		//	int h = 15;
		//	IntMatrix C = IntMatrix(B, h);
		//	OutputMatrixVer1(C, "Mtx C copy mtx B + 15", file);
		//	//IntMatrix D = IntMatrix(B);
		//	//OutputMatrixVer1(D, "Mtx D copy mtx B", file);
		//	RandomFill(C, 'C', file);
		//	OutputMatrixVer1(C, "Mtx C new view", file);
		//	//double sr = double(C);
		//	//fprintf(file, "Average mtx 'C': %lf\n\n", sr);
		//	//IntMatrix E = IntMatrix(h);
		//	//OutputMatrixVer1(E, "Mtx E size 1 x 1 with element 15", file);
		//	fprintf(file, "-----------------------\n\n");
		//	//~9
		//	fprintf(file, "Lab 9:\n\n");
		//	IntMatrix F(2, 2);
		//	OutputMatrixVer2(F, "Mtx F before assignment mtx C", file);
		//	F = C;
		//	OutputMatrixVer2(F, "Mtx F after assignment mtx C", file);
		//	IntMatrix G(3, 4);
		//	RandomFill(G, 'G', file);
		//	OutputMatrixVer2(G, "New mtx G 3 x 4", file);
		//	//fprintf(file, "Average mtx 'F': %lf\n\n", double(F));
		//	//fprintf(file, "Average mtx 'G': %lf\n\n", double(G));
		//	/*fprintf(file, "Comparison:\nmtx F < mtx G? %s\n", (F < G) ? "true" : "false");
		//	fprintf(file, "mtx F <= mtx G? %s\n", (F <= G) ? "true" : "false");
		//	fprintf(file, "mtx F > mtx G? %s\n", (F > G) ? "true" : "false");
		//	fprintf(file, "mtx F >= mtx G? %s\n", (F >= G) ? "true" : "false");*/
		//	fprintf(file, "mtx F == mtx G? %s\n", (F == G) ? "true" : "false");
		//	fprintf(file, "mtx F != mtx G? %s\n\n", (F != G) ? "true" : "false");
		//	F[0][0] = 34;
		//	OutputMatrixVer2(F, "Mtx F first el was changed", file);
		//	F += h;
		//	G -= h;
		//	OutputMatrixVer2(F, "Mtx F += 15", file);
		//	OutputMatrixVer2(G, "Mtx G -= 15", file);
		//	fprintf(file, "-----------------------\n\n");
		//	//~10
		//	fprintf(file, "Lab 10:\n\n");
		//	OutputMatrixVer2(F, "Mtx F", file);
		//	OutputMatrixVer2(G, "Mtx G", file);
		//	IntMatrix H(4, 5);
		//	RandomFill(H, 'H', file);
		//	IntMatrix T = 5;
		//	IntMatrix Hh = 17 + T;
		//	//bool flag = T == 5;
		//	//printf("%d", flag);
		//	OutputMatrixVer2(H, "New mtx H 4 x 5", file);
		//	OutputMatrixVer2(F + G, "Sum of F and G", file);
		//	OutputMatrixVer2(F - G, "Diff between F and G", file);
		//	OutputMatrixVer2(F * H, "Composition of F and H", file);
		//	fprintf(file, "-----------------------\n\n");
		//}
		//~11
		fprintf(file, "Lab 11:\n\n");
		try
		{
			IntMatrix AB(3, 4);
			int a = AB[1][4];
		}
		catch (Exception& e) {
			e.Message();
		}
		fprintf(file, "-----------------------\n\n");
		fclose(file);
	}
	else
		printf("File don't exists\n");
	return;
}