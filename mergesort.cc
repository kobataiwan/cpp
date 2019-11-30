#include <iostream>

using namespace std;

void 
right_shift(
    unsigned data[],
    unsigned size 
)
{
    unsigned tmp = data [size - 1];
#if 1

    cout << "size: " << size << endl;
    for (unsigned i = 0; i < size; i ++) {
        cout << data[i] << " ";
    }
    cout << endl;
#endif
    for (signed j = (size - 2); j >= 0; j--) {
        data[j + 1] = data [j];
    }
    data [0] = tmp;
#if 0
    cout << "after: " << endl;

    for (unsigned i = 0; i < size; i ++) {
        cout << data[i] << " ";
    }
    cout << endl;
#endif
}

void 
arrange (
    unsigned ldata[],
    unsigned ls,
    unsigned rdata[],
    unsigned rs) 
{
    cout << "ls: " << ls << "rs: " << rs << endl;
    for (unsigned i = 0; i < ls + rs; i ++) {
        cout << ldata[i] << " ";
    }
    cout << endl;
   for (unsigned i = 0; i < rs; i ++) {
       for (unsigned j = 0; j < ls + i; j ++) {
           if (ldata[j] > rdata[i]) {
                right_shift (ldata + j, ls + i - j + 1
                );
               break;
           }
       }
   }
}

void 
mergesort (
    unsigned data[], 
    unsigned size) 
{
    unsigned div = size / 2;
    if (size == 1) {
        return;
    }
    // 
    // left
    //
    mergesort (data, div);
    //
    // right
    //
    mergesort (data + div, size - div);
    //
    // merge
    //
    arrange (data, div, data + div, size - div);
    cout << "merge ";
    for (unsigned idx = 0; idx < size; idx ++) {
        cout << data[idx] << " ";
    }
    cout << endl;
}

int main () {
	unsigned data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergesort (data, 10);
}