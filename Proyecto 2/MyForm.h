#pragma once 
#include "Controladora.h"

namespace WForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Graphics^ g = CreateGraphics();
			BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
			BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
			Juego = new Controladora(bf->Graphics);
			bmpNave = gcnew Bitmap("nave.jpg");
			bmpBalas = gcnew Bitmap("balas.png");
			bmpEnemigos = gcnew Bitmap("spaceinvaders.png");
			bmpBombas = gcnew Bitmap("bullet.jpg");
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete Juego;
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		Controladora* Juego;
		Bitmap^ bmpNave;
		Bitmap^ bmpEnemigos;
		Bitmap^ bmpBalas;
		Bitmap^ bmpBombas;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 557);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		if (Juego->SeAcaboElJuego() == false) {
			bf->Graphics->Clear(Color::White);
			Juego->DibujarNave(bf->Graphics, bmpNave);
			Juego->DibujarBalas(bf->Graphics, bmpBalas);
			Juego->DibujarEnemigos(bf->Graphics, bmpEnemigos);
			Juego->DibujarBombas(bf->Graphics, bmpBombas);
			Juego->ColisionBalas_NavesMalas();
			Juego->ColisionNaves();
			bf->Render(g);
			delete g, espacio, bf;
		}
		else {
			bf->Graphics->Clear(Color::White);
			if (Juego->ReturnGano()) label1->Text = "El juego se ha terminado, has ganado";
			else label1->Text = "El juego se ha terminado, has perdido";
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) Juego->DesplazarNave(direccion::izquierda);
		if (e->KeyCode == Keys::Right) Juego->DesplazarNave(direccion::derecha);
		if (e->KeyCode == Keys::Space) Juego->Disparar();
	}
	};
}
