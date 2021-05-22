#pragma once

namespace GraficoArduino {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private: System::Windows::Forms::Button^ btIniciar;
	private: System::Windows::Forms::Button^ btParar;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ gfTensao;
	private: System::IO::Ports::SerialPort^ portaSerial;
	private: System::Windows::Forms::ComboBox^ cbPortas;
	private: System::Windows::Forms::Timer^ temporizador;


	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btIniciar = (gcnew System::Windows::Forms::Button());
			this->btParar = (gcnew System::Windows::Forms::Button());
			this->gfTensao = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->portaSerial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->cbPortas = (gcnew System::Windows::Forms::ComboBox());
			this->temporizador = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gfTensao))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Porta";
			// 
			// btIniciar
			// 
			this->btIniciar->Location = System::Drawing::Point(139, 27);
			this->btIniciar->Name = L"btIniciar";
			this->btIniciar->Size = System::Drawing::Size(75, 23);
			this->btIniciar->TabIndex = 2;
			this->btIniciar->Text = L"Iniciar";
			this->btIniciar->UseVisualStyleBackColor = true;
			this->btIniciar->Click += gcnew System::EventHandler(this, &MyForm::btIniciar_Click);
			// 
			// btParar
			// 
			this->btParar->Location = System::Drawing::Point(220, 27);
			this->btParar->Name = L"btParar";
			this->btParar->Size = System::Drawing::Size(75, 23);
			this->btParar->TabIndex = 3;
			this->btParar->Text = L"Parar";
			this->btParar->UseVisualStyleBackColor = true;
			this->btParar->Click += gcnew System::EventHandler(this, &MyForm::btParar_Click);
			// 
			// gfTensao
			// 
			chartArea1->Name = L"ChartArea1";
			this->gfTensao->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->gfTensao->Legends->Add(legend1);
			this->gfTensao->Location = System::Drawing::Point(12, 56);
			this->gfTensao->Name = L"gfTensao";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Tensao";
			this->gfTensao->Series->Add(series1);
			this->gfTensao->Size = System::Drawing::Size(558, 300);
			this->gfTensao->TabIndex = 4;
			this->gfTensao->Text = L"chart1";
			// 
			// cbPortas
			// 
			this->cbPortas->FormattingEnabled = true;
			this->cbPortas->Location = System::Drawing::Point(12, 29);
			this->cbPortas->Name = L"cbPortas";
			this->cbPortas->Size = System::Drawing::Size(121, 21);
			this->cbPortas->TabIndex = 5;
			this->cbPortas->Click += gcnew System::EventHandler(this, &MyForm::cbPortas_Click);
			// 
			// temporizador
			// 
			this->temporizador->Tick += gcnew System::EventHandler(this, &MyForm::temporizador_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(583, 367);
			this->Controls->Add(this->cbPortas);
			this->Controls->Add(this->gfTensao);
			this->Controls->Add(this->btParar);
			this->Controls->Add(this->btIniciar);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"MyForm";
			this->Text = L"Monitor de Variável via Serial";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gfTensao))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void cbPortas_Click(System::Object^ sender, System::EventArgs^ e) {
	// Exibindo portas com disponiveis
	cbPortas->Items->Clear();
	for each (String ^ porta in portaSerial->GetPortNames())
	{
		cbPortas->Items->Add(porta);
	}
}
private: System::Void btIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		portaSerial->PortName = cbPortas->Text;
		portaSerial->Open();
	}
	catch (...)
	{
		MessageBox::Show("Porta Não conectada", "ERRO");
	}
	temporizador->Enabled = true;
}
private: System::Void btParar_Click(System::Object^ sender, System::EventArgs^ e) {
	temporizador->Enabled = false;
	portaSerial->Close();
}
int tempo = 0;
private: System::Void temporizador_Tick(System::Object^ sender, System::EventArgs^ e) {
	String^ dadoRecebido = portaSerial->ReadLine();
	array<String^>^ substrings = dadoRecebido->Split(' ');
	double tensao = Convert::ToDouble(substrings[1], System::Globalization::NumberFormatInfo::InvariantInfo);
	tempo += 1;
	gfTensao->Series["Tensao"]->Points->AddXY(tempo, tensao);
}
};
}
/* Codigo arduino
double tensao;
int contador;
void setup() {
  contador = 0;
  Serial.begin(9600);
}
void loop() {
  tensao = sin((contador + random(0,10))/100.0);
  Serial.println("SENSOR " + String(tensao));
  contador+=10;
  delay(300);
}
*/
