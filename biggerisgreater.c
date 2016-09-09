/*
 ============================================================================
 Name        : [Hackerrank]  BiggerIsGreater.c
 Author      : UnlimitedJoy
 Version     :
 Copyright   : Code for the hankerrank contest
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_W 101

void swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void do_quick_sort(char s[], int left, int right) {
	int i = left, j = right;
	char pivot = s[left];
	do {
		while (s[i] < pivot && i < right)
			++i;
		while (s[j] > pivot && j > left)
			--j;
		if (i <= j) {
			swap(s + i, s + j);
			++i, --j;
		}
	} while (i <= j);
	if (left < j)
		do_quick_sort(s, left, j);
	if (i < right)
		do_quick_sort(s, i, right);
}

int find_min_letter_in_string(char s[], int index) {
	int i = strlen(s) - 1, ofs = 0, ofs_tmp = 0, key = 0;
	while (i > index) {
		ofs_tmp = (int) (s[i] - s[index]);
		if (ofs_tmp <= 0) {
			--i;
			continue;
		} else {
			if (ofs > ofs_tmp || ofs == 0) {
				ofs = ofs_tmp;
				key = i;
			}
		}
		--i;
	}
	if (ofs > 0) {
		return key;
	}
	return -1;
}

void rearrange(char s[]) {
	int len_s = strlen(s);
	int i = len_s - 2;
	int key = -1;
	if (len_s > 1) {
		while (i >= 0) {
			key = find_min_letter_in_string(s, i);
			if (key > 0) {
				swap(s + i, s + key);
				do_quick_sort(s, i + 1, strlen(s) - 1);
				printf("%s\n", s);
				return;
			}
			i--;
		}
	}
	printf("no answer\n");
}

int main(void) {

	int t = 0, T = 0;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	while (t < T) {
		char w[MAX_LEN_W];
		scanf("%s", w);
		rearrange(w);
		t++;
	}

	return EXIT_SUCCESS;
}
