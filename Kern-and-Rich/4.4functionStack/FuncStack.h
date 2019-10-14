/*���������� 4.4. �������� �������, 
� ������� ������� ����� ���� �� 
�������� ������� ������� ����� 
(� ����������� ��� � �����), 
����������� ��� � �����, ������ 
������� ��� ������� �������� �����. 
������� ������� ������� �����.*/

double pfse(void) {
	
	if (sp > 0)
		return val[sp-1];
	else {
		printf("ошибка: стек пуст\n");
		return 0.0;
	}

}

//Дублировать элемент в стеке
void duplStack(void) {

	if (sp < MAXVAL)
		val[sp++] = val[sp-1];
	else
		printf("ошибка: стек полон, %g не дублируется\n", val[sp]);
	}


//Меняет местами 2-а верхних элемента стека
void change12(void) {
	double intermed;
	if (sp > 1) {
		intermed = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = intermed;
	}
	else printf("ошибка: в стеке один эелемент\n");

}

//Очищает весь стек
void clrStack() {

	if (sp > 0) 
		for (int i = sp; i <= 0; i--) 
			val[i] = NULL;

}
