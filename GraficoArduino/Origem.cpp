#include "MyForm.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:main")

using namespace System;
using namespace System::Windows::Forms;

int main()
{
	GraficoArduino::MyForm form;
	Application::Run(% form);
}