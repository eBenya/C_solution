//old realization
void random_board(int *a, int size) {
	//*a = rand() % (size);

	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++){

			*(a + (i * DIM_MAX) + j) = rand() % (size);

			for (int k = 0; k <= i; k++)
				for (int l = 0; (l < d) && ((i*d + j) > (k*d + l)); l++) {

					if (*(a + (i * DIM_MAX) + j) == *(a + (k * DIM_MAX) + l)) {
						*(a + (i * DIM_MAX) + j) = rand() % (size);
						k = 0;
						l = -1;
					}
				}
		}
}


//n1 = y(столбец(column)), n2 = x(строка(string))
void random_matrix(int *a, int n1, int n2) {

	int size = n1 * n2;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++){

			*(a + (i * n1) + j) = rand() % (size);

			for (int k = 0; k <= i; k++)
				for (int l = 0; (l < n2) && ((i*n1 + j) > (k*n1 + l)); l++) {

					if (*(a + (i * n1) + j) == *(a + (k * n1) + l)) {
						*(a + (i * n1) + j) = rand() % (size);
						k = 0;
						l = -1;
					}
				}
		}
}