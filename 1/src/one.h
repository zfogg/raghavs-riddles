
int _tmp$;
#define SWAP(a, b) { _tmp$ = list[a]; list[a] = list[b]; list[b] = _tmp$; }


int randBetween(int min, int max);

int partition(int* list, int left, int right, int pivotIndex);

int select(int* list, int left, int right, int n);

int median(int* list, int size);

