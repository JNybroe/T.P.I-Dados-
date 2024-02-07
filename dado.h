#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

///Dados
void dibujarDados(int dado[], int caraDado){
	int ubicacion=0;
	for(int k=1;k<=6;k++){
	rlutil::locate(1+ubicacion,1);
	///Posicion X
	for(int i=0;i<=8;i++){
		cout<<(char)220;
	}
	rlutil::locate(1+ubicacion,5);
	for(int i=0;i<=7;i++){
		cout<<(char)220;
	}
	///Posicion Y
	for(int j=2;j<=5;j++){
		rlutil::locate(1+ubicacion,j);
		cout<<(char)219;
	}
	for(int j=2;j<=5;j++){
		rlutil::locate(9+ubicacion,j);
		cout<<(char)219;
	}
	ubicacion=k*10;
	}
	ubicacion=10;
	rlutil::locate(1,6);
	PlaySound(TEXT("MezclarDados.wav"), NULL, SND_ASYNC);
	cout<<"Mezclando dados";
	for(int i=0;i<5;i++){
		Sleep(450);
		cout<<".";
	}
	rlutil::locate(1,6);
	cout<<"                                                                 ";
	PlaySound(TEXT("LanzarDados.wav"), NULL, SND_ASYNC);
	Sleep(1100);
    rlutil::locate(0,0);

	for(int i=0;i<=5;i++){
        ubicacion=i*10;
		Sleep(rand()%100);
		switch(dado[i]){
		case 1:
			rlutil::locate(5+ubicacion,3);
			cout<<(char)220;
			break;
		case 2:
			rlutil::locate(3+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,4);
			cout<<(char)220;
			break;
		case 3:
			rlutil::locate(3+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(5+ubicacion,3);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,4);
			cout<<(char)220;
			break;
		case 4:
			rlutil::locate(3+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(3+ubicacion,4);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,4);
			cout<<(char)220;
			break;
		case 5:
			rlutil::locate(3+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(5+ubicacion,3);
			cout<<(char)220;
			rlutil::locate(3+ubicacion,4);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,4);
			cout<<(char)220;
			break;
		case 6:
			rlutil::locate(3+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,2);
			cout<<(char)220;
			rlutil::locate(3+ubicacion,3);
			cout<<(char)220;
			rlutil::locate(3+ubicacion,4);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,3);
			cout<<(char)220;
			rlutil::locate(7+ubicacion,4);
			cout<<(char)220;
			break;
		default:
			break;
		}
	}
	rlutil::locate(1,7);
}

#endif // DADO_H_INCLUDED
