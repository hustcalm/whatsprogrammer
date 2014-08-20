#include <iostream>
#include <vector>

/*
int main()
{
    srand((unsigned int)time(NULL));
    std::vector<int> random_cards;
    const int count = 54;
    int cards[count];
    for(int i = 0; i < count; ++i)
        cards[i] = i+1;
    for(int i = count; i > 0; --i) {
        int index = rand() % i;
        random_cards.push_back(cards[index]);
        cards[index] = cards[i-1];
    }
    std::copy(random_cards.begin(), random_cards.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    return 0;
}
*/

/*
Poker[N]

for (i = 0; i < N; ++i)

{

k = rand() % ( i + 1)

if (i != k)

{

switch(Poker[k], Poker[i]);

}

}
*/

void Swap(int* arr, int i, int j)
{
    if(i != j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void Shuffle1(int* arr, int len)
{
    if(len <= 0) return;
    int i = len;
    while(--i) {
        int idx = rand()%(i+1);
        Swap(arr, i, idx);
    }
}

void Shuffle2(int* arr, int len)
{
    for(int i = 0; i < len; i++) {
        int idx = rand()%(i+1);
        Swap(arr, i, idx);
    }
}

int main()
{
    int arr[54];
    int len = 54;
    int i = len;
    while(i--) {
        std::cout << i << " ";
        arr[i] = i + 1;
    }
    std::cout<<std::endl;

    for(i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;

    Shuffle1(arr, len);

    for(i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;
    return 0;
}
