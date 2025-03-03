/* Un vector {1,2,3,4,5,6}
 
Vamos a buscar el primer elemento par
 
#include <algorithm>
find_if

*/

#include <iostream> 
#include <vector>
#include <algorithm>

bool IsEven (int i) {
    return ((i%2)==0);
  }

int main() {
    std::vector <int> myVector = {1,2,3,4,5,6};
    std::vector<int>::iterator it = std::find_if (myVector.begin(), myVector.end(), IsEven);
    std::cout << "The first even value is " << *it << '\n';
    return 0;
}