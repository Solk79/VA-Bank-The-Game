#include "MainWindow.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CourseWork::MainWindow form;
	Application::Run(% form);
}