#include <cmath>
#include "Objects.h"
#include "Functions.h"
#include "WF.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FEM::WF WF;
	Application::Run(%WF);
}