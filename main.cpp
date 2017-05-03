#include <iostream>
#include <mutex>
#include "Singleton.h"

using namespace std;

class Dummy : public Singleton<Dummy>
{
	private:
		Dummy() {}
		~Dummy() {}
	public:
		void SayHello()
		{
			cout << "I'm a dummy." << endl;
		}

		friend Singleton<Dummy>;
};

int main()
{
	//Dummy dummy = Dummy::instance();
	Dummy::instance().SayHello();
	return 0;
}
