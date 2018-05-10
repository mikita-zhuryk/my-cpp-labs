#include "Lab9Form.h"
#include "Adult9.h"
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv) {
	srand(std::time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab9Form::MyForm form;
	Application::Run(%form);
	return 0;
}