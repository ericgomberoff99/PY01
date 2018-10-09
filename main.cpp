#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;



void ingresar_pedidos(float pedido[3][3],string tipo_prenda[3],string tipo_pedido[3]){

    cout << "---- Ingrese su pedido a continuación: ----" << endl;

    int cantidad; float kg_prenda;

    for (int i = 0; i < 3 ; ++i) {

    cout << "Ingrese el pedido para " << tipo_pedido[i] << ":" << endl;
    cout << "\n";


        for (int j = 0; j < 3; ++j) {

            cout << tipo_prenda[j] << ":" << endl;
            cout << "\n";
            cout << "Cantidad (unidades)==> ";
            cin >> cantidad;
            cout << "Kg/Prenda==> ";
            cin >> kg_prenda;
            cout << "\n";

            pedido[i][j] = cantidad * kg_prenda;

        }
    }


    }

void visualizar_pedido(float pedido[3][3],string tipo_prenda[3],string tipo_pedido[3]){

    for (int i = 0; i < 3; ++i) {

        cout << "--- " << tipo_pedido[i] << " ---" << endl;

        for (int j = 0; j < 3; ++j) {

            cout << tipo_prenda[j] << ": ";
            cout << setw(5) <<"[" << pedido[i][j] << "]" << endl;

        }

        cout << "\n";
    }


}

int dias_en_mes(int mes){

    int dias_x_mes;

    switch (mes)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            dias_x_mes = 30;
            break;

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias_x_mes = 31;
            break;

        case 2:{
            if(mes%4==0 and mes&100!=0 or mes%400==0)
                dias_x_mes = 29;
            else
                dias_x_mes = 28;
            break;
        }

    }

    return dias_x_mes;
}

string dia_a_fecha(int dias_a_sumar) {

    //FECHA ACTUAL

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    int anno_actual, mes_actual, dia_actual;
    int dias_x_mes, dia, mes, anno;

    anno_actual = (now->tm_year + 1900);
    mes_actual = (now->tm_mon + 1);
    dia_actual = (now->tm_mday);

    dia = dia_actual;
    mes = mes_actual;
    anno = anno_actual;


    for (int i=0;i<dias_a_sumar;i++)
    {
        dia++;
        if (dia > dias_en_mes(mes) )
        {
            dia = 1;
            mes++;
            if (mes==13)
            {
                mes = 1;
                anno++;
            }
        }
    }

    string resultado;

    string s_dia = to_string(dia);
    string s_mes = to_string(mes);
    string s_anno = to_string(anno);


    resultado = s_dia + '-' + s_mes + '-' + s_anno;


    return resultado;
}





void calculo_tiempos(float pedido[3][3], float velocidad[3][3][4],string tipo_pedido[3]){

    float tiempo_total = 0,temporal1, suma = 0;
    float tiempos_pedido[3];



    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 4; i++) {

                temporal1 = pedido[k][j] / velocidad[k][j][i];
                suma += temporal1;

            }
        }

        tiempos_pedido[k] = suma;
        tiempo_total += suma;
        suma = 0;

        cout << "El tiempo de espera de la tela " << tipo_pedido[k] << ": " << tiempos_pedido[k] << " horas." << endl;
    }

    cout << "El tiempo de espera total es : " << tiempo_total << " horas." << endl;
    cout << "\n";

    // Calculo de la fecha de ENTREGA

    int dia,mes, anno, hoy_dia, hoy_mes, hoy_anno, dias_mes;




    for (int l = 0; l < 3; ++l) {
        dia = int((tiempos_pedido[l]/24));
        if(tiempos_pedido[l]/24!=dia)
            dia++;
        cout << "Recoger el pedido de " << tipo_pedido[l] << " el " << dia_a_fecha(dia) << ", en " << dia << " dias." <<  endl;


    }


    
}


void calculo_materia_prima(){
    float hilo_jersey;
    float hilo_pique;
    float hilo_franela;
    
    //hilo_jersey= kgtela/0.7;
    //hilo_pique= kgtela/0.5;
    //hilo_franela= kgtela/0.3;
    
}
    
//kg_tela/rendimiento
    
void calculo_costos(){
    
}

int main() {

    float pedido[3][3];

    string tipo_prenda[3] = {"Polo", "Camisa", "Cuellos"};
    string tipo_pedido[3] = {"Jersy", "Pique", "Franela"};

    float velocidad[3][3][4] = {

            {       //Jersy
                    {1,10,20,0.2},//Polos
                    {1,10,20,0.5},//Camisas
                    {1,10,20,0.05}//Cuellos

            },

            {       //Pique
                    {1,10,20,0.22},//Polos
                    {1,10,20,0.33},//Camisas
                    {1,10,20,0.04}//Cuellos

            },

            {       //Franela
                    {1,10,20,0.25},//Polos
                    {1,10,20,0.50},//Camisas
                    {1,10,20,0.05}//Cuellos

            }
    };


    ingresar_pedidos(pedido, tipo_prenda, tipo_pedido);
    visualizar_pedido(pedido, tipo_prenda, tipo_pedido);

    calculo_tiempos(pedido,velocidad, tipo_pedido);



    return 0;
}
