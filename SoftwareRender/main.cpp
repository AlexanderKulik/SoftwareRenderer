#include "Application.h"

int main(int argv, char* argc[])
{

	Application::GetInstance()->Init();
	Application::GetInstance()->Run();
	Application::GetInstance()->Cleanup();

	return 0;
}