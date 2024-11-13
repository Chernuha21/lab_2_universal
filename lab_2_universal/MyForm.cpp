#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab2universal::MyForm form;
	Application::Run(% form);
}
#pragma once

namespace WindowsFormsApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(12, 12);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(760, 540);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->pictureBox1);
            this->Name = L"MyForm";
            this->Text = L"Графические фигуры";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        // Обработчик события Paint для PictureBox
        System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
            // Получаем объект Graphics
            Graphics^ g = e->Graphics;

            // Рисуем линию
            Pen^ blackPen = gcnew Pen(Color::Black, 2.0f);
            g->DrawLine(blackPen, 10, 10, 200, 10);

            // Рисуем прямоугольник
            Pen^ redPen = gcnew Pen(Color::Red, 3.0f);
            g->DrawRectangle(redPen, 10, 30, 100, 50);

            // Заполняем прямоугольник
            SolidBrush^ blueBrush = gcnew SolidBrush(Color::Blue);
            g->FillRectangle(blueBrush, 120, 30, 100, 50);

            // Рисуем эллипс
            Pen^ greenPen = gcnew Pen(Color::Green, 2.0f);
            g->DrawEllipse(greenPen, 10, 100, 150, 80);

            // Заполняем эллипс
            SolidBrush^ yellowBrush = gcnew SolidBrush(Color::Yellow);
            g->FillEllipse(yellowBrush, 170, 100, 150, 80);

            // Рисуем сектор (дугу)
            Pen^ purplePen = gcnew Pen(Color::Purple, 2.0f);
            g->DrawArc(purplePen, 10, 200, 150, 150, 45, 90);

            // Заполняем сектор
            SolidBrush^ orangeBrush = gcnew SolidBrush(Color::Orange);
            g->FillPie(orangeBrush, 170, 200, 150, 150, 45, 90);
        }
    };
}
