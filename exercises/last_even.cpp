/* Un vector {1,2,3,4,5,6}
 
Vamos a buscar el ultimo elemento par
 
#include <algorithm>
find_if */

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector <int> myVector = {1,2,3,4,5,6};
    //std::reverse(myVector.begin(), myVector.end());
    std::vector<int>::reverse_iterator it = std::find_if (myVector.rbegin(), myVector.rend(), [](int a){return a%2 == 0;});
    std::cout << "The last even value is " << *it << '\n';

    return 0;
}