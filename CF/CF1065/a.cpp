namespace a {
void func() {

}
}
namespace b {
void func() {

}
}

using namespace a;
using namespace b;

int main() {
    func();

}