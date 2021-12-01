#include <iostream>
#include <windows.h> // Permite reproducir sonidos con PlaySound()
#include <string>
#include <locale> //Para poner el idioma en español
#include <stdlib.h> //Para limpiar la consola
#include <dialogos.h> //Aqu[i se encuentran todos los diálogos
#include <limits> // Permitirá validar los valores // No lo terminé usando, pero usualmente necesitas incluirlo para std::cin.ignore();

	void Dialogo(std::string str) // Muestra los dialogos letra por letra con la voz de sans
	{
		std::system("CLS");

		int sansSpeed = 1; //Dicta la velocidad con la que se muestran las letras

		PlaySound(NULL, 0, 0);
		Sleep(1000);

		int numeroLetras = 0;
		std::string dialogo = str;
		
		while (dialogo[numeroLetras] != '\0')
		{
			std::cout << str[numeroLetras];
			if (numeroLetras % 3 == 0)
			{
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("sans.wav"), NULL, SND_ASYNC);
			}
			Sleep(sansSpeed);	
			numeroLetras++;
		}	

		Sleep(1500);
		std::cout << std::endl << std::endl;

		PlaySound(TEXT("Kid A Mnesia.wav"), NULL, SND_LOOP | SND_ASYNC);
	}

	int UnoDos() //Le pide al usuario introducir uno o dos
	{
		// Boleano para comprobar que el valor sea válido

		int x = 0;
		do {
			std::cout << "\nIntroduce tu respuesta: ";
			std::cin >> x;
			if (x != 1 && x != 2)
			{
				std::cout << "Número inválido. Intenta otra vez." << std::endl;
				std::cin.clear();
				std::cin.ignore(9223372036854775807, '\n'); //Por alguna razón no encontró "std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');" Válido, entonces busqué el valor de "std::numeric_limits<std::streamsize>::max()", que me dió "9223372036854775807", así que lo remplacé con eso.
			}
		} while (x != 1 && x != 2);
		return x;
	};

	void Ending(std::string str)
	{
		std::cout << "Presiona ENTER para continuar" << std::endl;

		std::cin.get();
		std::cin.get();

		std::system("CLS");

		std::string endingText = str;

		std::cout << endingText << std::endl;
	}


int main()
{
	setlocale(LC_ALL, "spanish");

	// Inicio del juego
	PlaySound(TEXT("Kid A Mnesia.wav"), NULL, SND_LOOP | SND_ASYNC);

	std::cout << "Bienvenido a mi juego.\n\nTendrás que tomar decisiones presionando los números que aparecerán en la pantalla y confirmando con la tecla ENTER.\n\nEspero que lo disfrutes.\n\nPresiona ENTER para comenzar\n";
	std::cin.clear();
	std::cin.ignore(9223372036854775807, '\n'); //También lo usamos aquí para limpiar el buffer antes de empezar con el juego.

	Dialogo(intro);
	std::cout << "1. Contestas el celular." << std::endl;
	std::cout << "2. No contestas el celular." << std::endl;
	if (UnoDos() == 1)
	{
		Dialogo(a1); 
		std::cout << "1. Aceptas el encuentro." << std::endl;
		std::cout << "2. Rechazas el encuentro." << std::endl;
		if (UnoDos() == 1)
		{
			Dialogo(a2);
			std::cout << "1. Jalas el gatillo." << std::endl;
			std::cout << "2. No jalas el gatillo." << std::endl;
			if (UnoDos() == 1)
			{
				Dialogo(a3);
				Ending("Trailer de Squid Game temporada 2 100% Real no fake Ending");
			}
			else
			{
				Dialogo(b3);
				Ending("Ozymandias no existe, son los papás Ending");
			}
		}
		else
		{
			Dialogo(b2);
			goto b1;
		}
	}
	else
	{
		Dialogo(b1);
	b1:
		std::cout << "1. Vas en Uber/taxi." << std::endl;
		std::cout << "2. Vas en camión." << std::endl;
		if (UnoDos() == 1)
		{
			Dialogo(c2);
			std::cout << "1. Vas en Uber." << std::endl;
			std::cout << "2. Vas en taxi." << std::endl;
			if (UnoDos() == 1)
			{
				Dialogo(e3);
				std::cout << "1. Pagas los altos costos de Uber con las escrituras de tu casa." << std::endl;
				std::cout << "2. Sales corriendo del Uber sin pagar." << std::endl;
				if (UnoDos() == 1)
				{
					Dialogo(l4);
					Ending("Sin casa y en deuda con el Coppel Ending");
				}
				else
				{
					Dialogo(j4);
					Ending("Al menos ya no estoy en deuda con el Coppel Ending");
				}
			}
			else
			{
				Dialogo(f3);
				std::cout << "1. Le pides al taxi si puede guardar silencio." << std::endl;
				std::cout << "2. Le dices al taxi que lo comprendes y que tú también odias a los de Uber." << std::endl;
				if (UnoDos() == 1)
				{
					Dialogo(k4);
					Ending("Bad Ending");
				}
				else
				{
					Dialogo(l4);
					Ending("Good Ending");
				}
			}
		}
		else
		{
			Dialogo(d2);
			std::cout << "1. Esperas el 420." << std::endl;
			std::cout << "2. Esperas el C-69." << std::endl;
			if (UnoDos() == 1)
			{
				Dialogo(g3);
				std::cout << "1. Aceptas el toque." << std::endl;
				std::cout << "2. Rechazas el toque." << std::endl;
				if (UnoDos() == 1)
				{
					Dialogo(m4);
					Ending("Secta Marihuanera Ending");
				}
				else
				{
					Dialogo(n4);
					Ending("Plagio Otaku Ending");
				}
			}
			else
			{
				Dialogo(h3);
				std::cout << "1. Agradeces al camionero." << std::endl;
				std::cout << "2. No agradeces al camionero." << std::endl;
				if (UnoDos() == 1)
				{
					Dialogo(o4);
					Ending("We like Fortnite Ending");
				}
				else
				{
					Dialogo(p4);
					Ending("- Espera, ¡¿ESTE JUEGO TERMINÓ SIENDO UN SIMULADOR DE CITAS?!\n\n- Always has been” Ending");
				}
			}
		}
	}


	//Branching 
	/*
	if (UnoDos() == 1)
		{

		}
		else
		{

		}
	*/

	return 0;
}