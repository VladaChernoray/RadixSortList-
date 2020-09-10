int most_value();
int digit_finder(int num, int temp);

void radix_sort() {
	int less = 1;
	int more = most_value(head);
	struct node* back[10];
	struct node* front[10];
	struct node* temp;

	for (int i = less; i <= more; i++) {
		for (int count = 0; count <= 9; count++) {
			back[count] = NULL;
			front[count] = NULL;
		}
		for (temp = head; temp != NULL; temp = temp->next) {
			int digit = digit_finder(temp->key, i);

			if (front[digit] == NULL) {
				front[digit] = temp;
			}
			else {
				back[digit]->next = temp;
			}
			back[digit] = temp;
		}
		count = 0;

		while (front[count] == NULL) {
			count++;
		}

		while (count <= 9) {
			if (back[count + 1] != NULL)
			{
				back[count]->next = front[count + 1];
			}
			else
			{
				back[count + 1] = back[count];
			}
			count++;
		}
		back[9]->next = NULL;
	}
}

int most_value() {
	struct node* temp = head;
	int count = 0;
	int digit = 0;
	while (temp != NULL) {
		if (temp->key > count) {
			count = temp->key;
		}
		temp = temp->next;
	}

	while (count != NULL) {
		digit++;
		count = count / 10;
	}
	return(digit);
}

int digit_finder(int num, int temp) {
	for (int count = 0; count <= temp; count++) {
		int templ = num % 10;
		num = num / 10;
	}
	return(templ);
}
