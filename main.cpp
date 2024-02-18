#include <iostream>
#include <png_generator.h>

using namespace std;

int main(void)
{
    string chunk = png::CreateChuck("49484452", "00000001000000010802000000");
    cout << chunk << "\n";
    return 0;
}