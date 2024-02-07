#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

///Modo un solo jugador
///void mostrarReglas()
void mostrarReglas(){
	cout<<"El objetivo del juego es obtener al menos 500 puntos en la menor cantidad posible de rondas, o sacar una escalera en un lanzamiento.\n";
	cout<<"Una ronda está compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje.\n";
	cout<<"El puntaje de un lanzamiento está determinado por una serie de reglas que figuran en la sección Combinaciones ganadoras.\n";
	cout<<"El puntaje de la ronda será el valor máximo obtenido entre los 3 lanzamientos, con las siguientes excepciones:\n";
	cout<<" "<<(char)254<<" Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento\n";
	cout<<" "<<(char)254<<" Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje de la ronda entera sera 0.\n";
	cout<<"Para el caso de la opcion para 2 jugadores, los jugadores debe completar una ronda(3 lanzamientos) alternativamente.\n";
	cout<<endl;
	cout<<"Combinaciones ganadoras\n";
	cout<<(char)254<<" Suma de dados\n";
	cout<<"  Menos de 3 dados con valores iguales (cualquier combinación) Ejemplo: 6,5,5,2,2,1\n";
	cout<<"  Suma de los valores de todos los dados. Para el ejemplo sería 6+5+5+2+2+1=21\n";
	cout<<endl;
	cout<<(char)254<<" Trío X++ (X es el número del dado)\n";
	cout<<"  3 dados o más con el mismo valor (hasta 5 iguales). Ejemplo: 5, 5, 5,1,2,3.\n";
	cout<<"  X*10puntos. Para el ejemplo sería 5*10=50\n";
	cout<<endl;
	cout<<(char)254<<" Sexteto X (X es el número del dado)\n";
	cout<<"  6 dados iguales (menos para el número 6).\n";
	cout<<"  X*50 puntos\n";
	cout<<endl;
	cout<<(char)254<<" Escalera\n";
	cout<<"  Escalera (1, 2, 3, 4, 5,6)\n";
	cout<<"  Gana la partida en esa ronda\n";
	cout<<endl;
	cout<<(char)254<<" Sexteto6--\n";
	cout<<"  Seis 6\n";
	cout<<"  Pierde todos los puntos de la ronda\n";
}

///void dibujarFinRonda(int ronda,int puntajeObtenido, int puntajeFinal)
void dibujarFinRonda(int ronda,int puntajeObtenido[], int puntajeFinal[]){
    ///Dibuja X
    rlutil::locate(46,13);
    for(int i=0;i<=25;i++){
        cout<<(char)220;
    }
    rlutil::locate(46,19);
    for(int i=0;i<=25;i++){
        cout<<(char)223;
    }
    ///Dibuja Y
    rlutil::locate(46,13);
    for(int i=14;i<=18;i++){
    rlutil::locate(46,i);
        cout<<(char)219;
    }
    for(int i=14;i<=18;i++){
    rlutil::locate(71,i);
        cout<<(char)219;
    }
    rlutil::locate(49,15);
    cout<<"FIN DE LA RONDA N"<<(char)167<<ronda;
    rlutil::locate(49,16);
    cout<<"MAXIMO OBTENIDO: "<<puntajeObtenido[0]<<endl;
    rlutil::locate(49,17);
    cout<<"PUNTAJE TOTAL: "<<puntajeFinal[0]<<endl;
}

///void dibujarFinPartida(string nombre, int puntaje)
void dibujarFinPartida(string nombre, int puntaje[]){
    ///Dibuja X
    rlutil::locate(46,13);
    for(int i=0;i<=25;i++){
        cout<<(char)220;
    }
    rlutil::locate(46,19);
    for(int i=0;i<=25;i++){
        cout<<(char)223;
    }
    ///Dibuja Y
    rlutil::locate(46,13);
    for(int i=14;i<=18;i++){
        rlutil::locate(46,i);
        cout<<(char)219;
    }
    for(int i=14;i<=18;i++){
        rlutil::locate(71,i);
        cout<<(char)219;
    }
    rlutil::locate(50,15);
    cout<<"FIN DE LA PARTIDA\n";
    rlutil::locate(50,16);
    cout<<"JUGADOR: "<<nombre<<endl;
    rlutil::locate(50,17);
    cout<<"PUNTAJE FINAL: "<<puntaje[0]<<endl;
}

///Modo un Versus
///void dibujarSiguienteTurno(string nombrePrimero,string nombreSegundo,int ronda, int maximoJugador[])
void dibujarSiguienteTurno(string nombrePrimero,string nombreSegundo,int ronda, int maximoJugador[]){
	///Dibuja X
	rlutil::locate(43,12);
	for(int i=0;i<=31;i++){
		cout<<(char)220;
	}
	rlutil::locate(43,20);
	for(int i=0;i<=31;i++){
		cout<<(char)223;
	}
	///Dibuja Y
	rlutil::locate(46,13);
	for(int i=13;i<=19;i++){
		rlutil::locate(43,i);
		cout<<(char)219;
	}
	for(int i=13;i<=19;i++){
		rlutil::locate(74,i);
		cout<<(char)219;
	}
	rlutil::locate(55,14);
	cout<<"RONDA N"<<(char)167<<ronda;
	rlutil::locate(47,15);
	cout<<"SIGUIENTE TURNO: "<<nombreSegundo<<endl;
	rlutil::locate(49,17);
	cout<<"PUNTAJE "<<nombrePrimero<<": "<<maximoJugador[0]<<endl;
	rlutil::locate(49,18);
	cout<<"PUNTAJE "<<nombreSegundo<<": "<<maximoJugador[1]<<endl;
	rlutil::locate(43,21);
	system("pause");
	rlutil::cls();
}

///void dibujarFinRondaVersus(string nombrePrimero,string nombreSegundo,int ronda, int maximo[],int puntaje[]
void dibujarFinRondaVersus(string nombrePrimero,string nombreSegundo,int ronda, int maximo[],int puntaje[]){
///Dibuja X
rlutil::locate(38,13);
	for(int i=0;i<=48;i++){
		cout<<(char)220;
	}
	rlutil::locate(38,21);
	for(int i=0;i<=48;i++){
		cout<<(char)223;
	}
///Dibuja Y
rlutil::locate(46,13);
	for(int i=14;i<=20;i++){
		rlutil::locate(38,i);
		cout<<(char)219;
	}
	for(int i=14;i<=20;i++){
		rlutil::locate(86,i);
		cout<<(char)219;
	}
	rlutil::locate(53,15);
	cout<<"FIN DE LA RONDA N°"<<ronda;
	rlutil::locate(40,17);
	cout<<"JUGADOR "<<nombrePrimero<<endl;
	rlutil::locate(40,18);
	cout<<"MAXIMO OBTENIDO: "<<maximo[0]<<endl;
	rlutil::locate(40,19);
	cout<<"PUNTAJE TOTAL: "<<puntaje[0]<<endl;
	rlutil::locate(65,17);
	cout<<"JUGADOR  "<<nombreSegundo<<endl;
	rlutil::locate(65,18);
	cout<<"MAXIMO OBTENIDO: "<<maximo[1]<<endl;
	rlutil::locate(65,19);
	cout<<"PUNTAJE TOTAL: "<<puntaje[1]<<endl;
	rlutil::locate(43,22);
	system("pause");
	rlutil::locate(1,1);
}

///void dibujarFinPartidaVersus(string nombre, int puntaje)
void dibujarFinPartidaVersus(string nombre, int puntaje){
	///Dibuja X
	rlutil::locate(46,13);
	for(int i=0;i<=25;i++){
		cout<<(char)220;
	}
	rlutil::locate(46,19);
	for(int i=0;i<=25;i++){
		cout<<(char)223;
	}
	///Dibuja Y
	rlutil::locate(46,13);
	for(int i=14;i<=18;i++){
		rlutil::locate(46,i);
		cout<<(char)219;
	}
	for(int i=14;i<=18;i++){
		rlutil::locate(71,i);
		cout<<(char)219;
	}
	rlutil::locate(50,15);
	cout<<"FIN DE LA PARTIDA\n";
	rlutil::locate(50,16);
	cout<<"GANADOR: "<<nombre<<endl;
	rlutil::locate(50,17);
	cout<<"PUNTAJE FINAL: "<<puntaje<<endl;
}

#endif // MENUS_H_INCLUDED
