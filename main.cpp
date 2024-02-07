#include "rlutil.h"
#include "dadoFuncones.h"
#include "dado.h"
#include "menus.h"
int main () {
    srand(time(NULL));
	string nombreJugador,nombreJugador2, nombreGanador;
	int puntajeTotal[2], puntajeActual[2],maximoRonda[2]={0},ganadorPuntaje,mayorPuntaje=0;///Puntaje del juego
	int contadorRonda, contadorLanzamiento;///Contadores
	bool saco6,siguePartida=true,hayTriple, haySexteto, hayEscalera,sacoEscaleraJugador1,sacoEscaleraJugador2;
	const int caraDado=6;
	int dado[caraDado], numRepetido;

	///menu
	int input;
	int cursor=0;
	int opcion=1;
	do{
		rlutil::locate(1,1);
		cout<<"Mayor puntaje: "<<mayorPuntaje;
        PlaySound(TEXT("musicaFondo.wav"), NULL, SND_LOOP | SND_ASYNC |SND_NOSTOP);
		puntajeTotal[0]=0;
		puntajeTotal[1]=0;
		contadorRonda=1;
		rlutil::hidecursor();
		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::setColor(rlutil::WHITE);
		rlutil::locate(49,15+cursor);
		cout<<">";
		rlutil::locate(70,15+cursor);
		cout<<"<";
		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::locate(50,15);
		cout<<"Modo un solo jugador\n";
		rlutil::locate(50,16);
		cout<<"Modo versus \n";
		rlutil::locate(50,17);
		cout<<"Reglas del juego\n";
		rlutil::locate(50,18);
		cout<<"Salir del juego\n";
		input = rlutil::getkey();
		switch(input){
		case 14:
			Beep(1200,10);
			rlutil::locate(49,15+cursor);
			cout<<" ";
			rlutil::locate(70,15+cursor);
			cout<<" ";
			cursor--;
			if(cursor<0){
				cursor=0;
			}
			break;
		case 15:
			Beep(1200,10);
			rlutil::locate(49,15+cursor);
			cout<<" ";
			rlutil::locate(70,15+cursor);
			cout<<" ";
			cursor++;
			if(cursor>3){
				cursor=3;
			}
			break;
		case 1:
			switch(cursor){
			case 0: ///Modo un solo jugador
				rlutil::cls();
				puntajeTotal[0]=0;
				cout<<"Ingrese su nombre:";
				cin>>nombreJugador;
				acomodarNombreJugador(nombreJugador);
				rlutil::cls();
				while(puntajeTotal[0]<500){ ///Rondas
					maximoRonda[0]=0;
					saco6=false;
					contadorLanzamiento=0;
					for(int i=1;i<=3;i++){ ///Los 3 lanzamientos por ronda
						puntajeActual[0]=0;
						lanzarDados(dado, caraDado);
						dibujarDados(dado, caraDado);
						numRepetido=calcularNumRepetido(dado, caraDado);/// NUM QUE HIZO COMBO
						hayEscalera=verificarEscalera(dado, caraDado);
						haySexteto=verificarSexto(dado, caraDado);
						hayTriple=verificarTriple(dado,caraDado);
						rlutil::locate(8,0);
						cout<<"-----------------------------------------------------------\n";
						cout<<"JUGADOR: "<<nombreJugador<<" ||";
						if(hayEscalera){
                            cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
						}else{
						if(haySexteto || hayTriple){
							if(hayTriple){
								puntajeActual[0]=puntajeActual[0]+(numRepetido*10);
								cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
							}else{
								if(haySexteto && numRepetido!=6){
									puntajeActual[0]=puntajeActual[0]+(numRepetido*50);
									cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
								}else{
										saco6=true;
										cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
									}
								}
						}else{
							for(int j=0;j<=5;j++){
								puntajeActual[0]+=dado[j];
							}
							cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
						}
						}
						if(saco6){
							puntajeActual[0]=0;
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[0]<<endl;
						}else{
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[0]<<endl;
						}
						cout<<"-----------------------------------------------------------\n";
						cout<<"RONDA N"<<(char)167<<" "<<contadorRonda;
						contadorLanzamiento++;
						cout<<" || LANZAMIENTO N"<<(char)167<<" "<<contadorLanzamiento;
						if(hayEscalera){
                        cout<<" || Escalera "<<endl;
                            rlutil::anykey();
                            rlutil::cls();
							break;
						}else{
						if(hayTriple or haySexteto){
							if(hayTriple){
								cout<<" || Trio "<<numRepetido<<endl;
							}else{
								if(haySexteto and numRepetido!=6){
									cout<<" || Sexteto "<<numRepetido<<endl;
								}else{
									cout<<" || Sexteto 6 "<<endl;
								}
							}
						}else{
							cout<<" || Suma de dados"<<endl;
						}
						}
						rlutil::locate(1,12);
						system("pause");
						system("cls");
						if(i==1 or puntajeActual[0]>maximoRonda[0]){
                                maximoRonda[0]=puntajeActual[0];
                            }
						if(saco6){
                            maximoRonda[0]=0;
						}
					}
					if(hayEscalera){
                        rlutil::locate(40,12);
						cout<<"FELICIDADES GANASTE EL JUEGO POR ESCALERA!!!!\n";
						break;
					}
					puntajeTotal[0]+=maximoRonda[0];
					dibujarFinRonda(contadorRonda,maximoRonda,puntajeTotal);
					rlutil::locate(46,20);
					contadorRonda++;
					system("pause");
					rlutil::cls();
				}
				if(puntajeTotal[0]>mayorPuntaje){
                    mayorPuntaje=puntajeTotal[0];
				}
				dibujarFinPartida(nombreJugador, puntajeTotal);
				rlutil::locate(46,20);
				system("pause");
				rlutil::cls();
				break;

			case 1:///Modo Versus
				contadorRonda=1;
				rlutil::cls();
				cout<<"Ingrese el nombre del primer jugador: ";
				cin>>nombreJugador;
				cout<<"Ingrese el nombre del segundo jugador: ";
				cin>>nombreJugador2;
				acomodarNombreJugador(nombreJugador);
				acomodarNombreJugador(nombreJugador2);
				rlutil::cls();
				ganadorPuntaje=0;
                puntajeTotal[0]=0;
                puntajeTotal[1]=0;
				while(siguePartida){ ///Rondas
                    puntajeActual[1]=0;
				    sacoEscaleraJugador1=false;
                    sacoEscaleraJugador2=false;
                    saco6=false;
                    contadorLanzamiento=0;
                    hayEscalera=false;
                    maximoRonda[0]=0;
                    for(int i=1;i<=3;i++ ){
                        puntajeActual[0]=0;
						lanzarDados(dado, caraDado);
						dibujarDados(dado, caraDado);
						numRepetido=calcularNumRepetido(dado, caraDado);/// NUM QUE HIZO COMBO
						hayEscalera=verificarEscalera(dado, caraDado);
						haySexteto=verificarSexto(dado, caraDado);
						hayTriple=verificarTriple(dado,caraDado);
						rlutil::locate(8,0);
						cout<<"-----------------------------------------------------------\n";
						cout<<"JUGADOR: "<<nombreJugador<<" ||";
						if(hayEscalera){
                            cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
						}else{
						if(haySexteto || hayTriple){
							if(hayTriple){
								puntajeActual[0]=puntajeActual[0]+(numRepetido*10);
								cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
							}else{
								if(haySexteto and numRepetido!=6){
									puntajeActual[0]=puntajeActual[0]+(numRepetido*50);
									cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
								}else{
										saco6=true;
										cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
									}
								}
						}else{
							for(int j=0;j<=5;j++){
								puntajeActual[0]+=dado[j];
							}
							cout<< " PUNTAJE TOTAL: "<<puntajeTotal[0];
						}
						}
						if(saco6){
                            puntajeActual[0]=0;
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[0]<<endl;
						}else{
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[0]<<endl;
						}
						cout<<"-----------------------------------------------------------\n";
						cout<<"RONDA N"<<(char)167<<" "<<contadorRonda;
						contadorLanzamiento++;
						cout<<" || LANZAMIENTO N"<<(char)167<<" "<<contadorLanzamiento;
						if(hayEscalera){
							cout<<" || Escalera "<<endl;
							sacoEscaleraJugador1=true;
							rlutil::anykey();
                            rlutil::cls();
                            break;
						}else{
							if(hayTriple or haySexteto){
								if(hayTriple){
									cout<<" || Trio "<<numRepetido<<endl;
								}else{
									if(haySexteto and numRepetido!=6){
										cout<<" || Sexteto "<<numRepetido<<endl;
									}else{
										cout<<" || Sexteto 6 "<<endl;
									}
								}
							}else{
								cout<<" || Suma de dados"<<endl;
							}
						}
						rlutil::locate(1,12);
						system("pause");
						system("cls");
						if(i==1||puntajeActual[0]>maximoRonda[0]){
                                maximoRonda[0]=puntajeActual[0];
                            }
						if(saco6){
                            maximoRonda[0]=0;
						}
                        hayTriple=false;
                        haySexteto=false;
					}
					puntajeTotal[0]=puntajeTotal[0]+maximoRonda[0];
					///Siguente turno
					dibujarSiguienteTurno(nombreJugador,nombreJugador2,contadorRonda,puntajeTotal);
					saco6=false;
					contadorLanzamiento=0;
					maximoRonda[1]=0;
					for(int i=1;i<=3;i++ ){
					    puntajeActual[1]=0;
						lanzarDados(dado, caraDado);
						dibujarDados(dado, caraDado);
						numRepetido=calcularNumRepetido(dado, caraDado);/// NUM QUE HIZO COMBO
						hayEscalera=verificarEscalera(dado, caraDado);
						haySexteto=verificarSexto(dado, caraDado);
						hayTriple=verificarTriple(dado,caraDado);
						rlutil::locate(8,0);
						cout<<"-----------------------------------------------------------\n";
						cout<<"JUGADOR: "<<nombreJugador2<<" ||";
						if(hayEscalera){
							cout<< " PUNTAJE TOTAL: "<<puntajeTotal[1];
						}else{
							if(haySexteto || hayTriple){
								if(hayTriple){
									puntajeActual[1]=puntajeActual[1]+(numRepetido*10);
									cout<< " PUNTAJE TOTAL: "<<puntajeTotal[1];
								}else{
									if(haySexteto and numRepetido!=6){
										puntajeActual[1]=puntajeActual[1]+(numRepetido*50);
										cout<< " PUNTAJE TOTAL: "<<puntajeTotal[1];
									}else{
										saco6=true;
										cout<< " PUNTAJE TOTAL: "<<puntajeTotal[1];
									}
								}
							}else{
								for(int j=0;j<=5;j++){
									puntajeActual[1]+=dado[j];
								}
								cout<< " PUNTAJE TOTAL: "<<puntajeTotal[1];
							}
						}
						if(saco6){
							puntajeActual[1]=0;
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[1]<<endl;
						}else{
							cout<<" || PUNTAJE OBTENIDO: "<<puntajeActual[1]<<endl;
						}
						cout<<"-----------------------------------------------------------\n";
						cout<<"RONDA N"<<(char)167<<" "<<contadorRonda;
						contadorLanzamiento++;
						cout<<" || LANZAMIENTO N"<<(char)167<<" "<<contadorLanzamiento;
						if(hayEscalera){
							cout<<" || Escalera "<<endl;
							sacoEscaleraJugador2=true;
                            rlutil::anykey();
                            rlutil::cls();
							break;
						}else{
							if(hayTriple or haySexteto){
								if(hayTriple){
									cout<<" || Trio "<<numRepetido<<endl;
								}else{
									if(haySexteto and numRepetido!=6){
										cout<<" || Sexteto "<<numRepetido<<endl;
									}else{
										cout<<" || Sexteto 6 "<<endl;
									}
								}
							}else{
								cout<<" || Suma de dados"<<endl;
							}
						}
						rlutil::locate(1,12);
						system("pause");
						system("cls");
						if(i==1 || puntajeActual[1]>maximoRonda[1]){
                                maximoRonda[1]=puntajeActual[1];
                            }
						if(saco6){
                            maximoRonda[1]=0;
						}
						puntajeActual[1]=0;
						hayTriple=false;
                        haySexteto=false;
					}
					puntajeTotal[1]=puntajeTotal[1]+maximoRonda[1];
					dibujarFinRondaVersus(nombreJugador,nombreJugador2,contadorRonda,maximoRonda,puntajeTotal);
					rlutil::cls();
					contadorLanzamiento=0;
					contadorRonda++;
                    if(sacoEscaleraJugador1 or sacoEscaleraJugador2){
                        if(sacoEscaleraJugador1 and sacoEscaleraJugador2){
                            siguePartida=false;
                            if(puntajeTotal[0]>puntajeTotal[1]){
                                rlutil::locate(46,12);
                                cout<<"Gano "<<nombreJugador<<" por escalera!!!!";
                                ganadorPuntaje=puntajeTotal[0];
                                nombreGanador=nombreJugador;
                            }else{
                                rlutil::locate(46,12);
                                cout<<"Gano "<<nombreJugador2<<" por escalera!!!!";
                                ganadorPuntaje=puntajeTotal[1];
                                nombreGanador=nombreJugador2;
                            }
                            if(sacoEscaleraJugador1 and !sacoEscaleraJugador2){
                                ganadorPuntaje=puntajeTotal[0];
                                nombreGanador=nombreJugador;
                            }
                            if(!sacoEscaleraJugador1 and sacoEscaleraJugador2){
                                ganadorPuntaje=puntajeTotal[1];
                                nombreGanador=nombreJugador2;
                            }
                        }
                    }else{
                        if(puntajeTotal[0]>=500 or puntajeTotal[1]>=500){
                            siguePartida=false;
                            if(puntajeTotal[0]>puntajeTotal[1]){
                                ganadorPuntaje=puntajeTotal[0];
                                nombreGanador=nombreJugador;
                                if(puntajeTotal[0]>mayorPuntaje){
                                    mayorPuntaje=puntajeTotal[0];
                                }
                            }else{
                                ganadorPuntaje=puntajeTotal[1];
                                nombreGanador=nombreJugador2;
                                if(puntajeTotal[1]>mayorPuntaje){
                                    mayorPuntaje=puntajeTotal[1];
                                }
                            }
                        }
                    }
				}
				dibujarFinPartidaVersus(nombreGanador,ganadorPuntaje);
				rlutil::locate(46,20);
				system("pause");
				rlutil::cls();
				break;

			case 2:
				rlutil::cls();
				mostrarReglas();
				system("pause");
				rlutil::cls();
				break;
			case 3:
				opcion=0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		input=0;
	}while(opcion!=0);
	return 0;
}

