#include <iostream>

using namespace std;

unsigned debug = 0;

void swap (unsigned* a, unsigned* b) 
{
	unsigned tmp = *a;
	*a = *b;
	*b = tmp;
}

void 
dump_data (
	unsigned* data, 
	unsigned size) 
{
	unsigned idx = 0;

	for (idx = 0; idx < size; idx ++) {
		cout << data[idx] << " ";
	}
	cout << endl;

}

void 
arrange_in_place (
	unsigned* data, 
	unsigned size,
	unsigned* pivot_final_idx) 
{
	unsigned pivot = data[size/2 - 1 ]; 
	unsigned pivot_idx = size/2 - 1; 
	signed i = -1, j = 0;
	unsigned idx;

	for (j = 0; j < size; j ++) {
		if (j == pivot_idx) {
			continue;
		}
		cout << "data " << data[j] << ", pivot: " << pivot << endl;

		
		if (data[j] < pivot ) {
			((++i == pivot_idx) ? i++: i);
			swap (data + i, data +j);
		}
	}

	if (i >=0 && i > pivot_idx) {
		swap (data + i, data + pivot_idx);
		*pivot_final_idx = i;
	} else {
		*pivot_final_idx = pivot_idx;
	}
}

void 
quicksort (
	unsigned* data, 
	unsigned size)
{
	unsigned pivot_final_idx;
	if (size <= 1) {
		return;
	}

	arrange_in_place (data, size, &pivot_final_idx);
	cout << "pf: " << pivot_final_idx << endl;
	quicksort (data, pivot_final_idx);
	if (size <= (pivot_final_idx + 1)) {
		return;
	}
	cout << "right pf: " << pivot_final_idx << ", size: " << size - (pivot_final_idx + 1) << endl;
	quicksort (data + pivot_final_idx + 1, size - (pivot_final_idx + 1));
}

int main()
{
	unsigned data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	unsigned data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	unsigned idx = 0;

	quicksort(data, 10);

	for (idx = 0; idx < 10; idx ++) {
		cout << data[idx] << " ";
	}
	cout << endl;
	
	return 0;
}
