
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {

system("sudo timedatectl set-ntp false");   
system("sudo date --set '2021-02-04 15:30:52'");

    return 0;
}

