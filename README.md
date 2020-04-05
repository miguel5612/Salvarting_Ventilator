<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
![Build Status][build-url]
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

# Arduino_Respirator
Arduino low cost respirator to assist coronavirus crisis.

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Getting Started](#Getting-Started)
  * [Objetive](#Objective)
* [List of Materials](#Materials)
* [Wiring](#Wiring)
  * [Sensors](#Sensors)
  * [Arduino](#Arduino)
  * [ESP8266](#ESP8266)
* [User Manual](#Manuals)
* [Sensor manufacturers](#Sensor-manufacturers)
* [Contributing](#Contributing)
* [Authors](#TEAM)
* [Partners](#Partners)

# Objective
To design a low cost/ high sofisticated respirator using local materials
# Materials
**Note**: Updated 04.04.2020
## Electronics:
| Name | Provider | Pricing (COP) |
| ------------- | ------------- |  ------------- |
| Arduino Nano  | [vistronica](https://www.vistronica.com/board-de-desarrollo/arduino/board/arduino-nano-v3-0-atmega328-ch340-sin-cable-detail.html)  | $13.294 |
| Driver DRV8825| [vistronica](https://www.vistronica.com/robotica/motores/drivers-de-motores/driver-motor-paso-a-paso-drv8825-pololu-detail.html)  | $34.633 |
| BMP180 Sensor | [vistronica](https://www.vistronica.com/sensores/presion/modulo-barometro-bmp180-detail.html) | $11.441 |
| Stepper motor Nema 17  | [vistronica](https://www.vistronica.com/robotica/motores/motor-paso-a-paso/motor-paso-a-paso-5-6kgcm-nema-17-para-impresora-3d-detail.html)  | $52.000 |
| Buzzer Module | [vistronica](https://www.vistronica.com/modulos/modulo-buzzer-detail.html) | $4.373 |
| Power Supply 12V@3A | [vistronica](https://www.vistronica.com/fuente-de-voltaje/adaptadores/fuente-de-voltaje-dc-de-12v-a-3a-detail.html)  | $20.049 |
| Emergency Button  | [vistronica](https://www.vistronica.com/conectores-cables-y-switches/interruptor-de-presion-normalmente-abierto-la38-11bn-detail.html)  | $9.187 |
| breadboard |[vistronica](https://www.vistronica.com/robotica/motores/drivers-de-motores/driver-motor-paso-a-paso-drv8825-pololu-detail.html)  | $8.320  |
| utp wire (3-Meters) | [Homecenter](https://www.homecenter.com.co/homecenter-co/product/142905/Cable-1m-utp-Categoria-6-23AWG/142905)  | $7.800 |
| Potentiometer 4.7K x 3 | [vistronica](https://www.vistronica.com/componentes-pasivos/potenciometro-wxd3-13-2w-4-7k-detail.html) | $23.082 |
| Start button | [vistronica](https://www.vistronica.com/conectores-cables-y-switches/suiche-pulsador-de-boton-iluminado-verde-46-mm-detail.html) | $7.557 |
| screw | [vistronica](https://www.vistronica.com/impresora-3d-y-cnc/varillas/varilla-roscada-acero-inoxidable-10mm-1-metro-detail.html) | $25.185 |
| T8 NUT | [vistronica](https://www.vistronica.com/impresora-3d-y-cnc/TuercaT8AntiBacklashParaVarillaTrapezoidal1Hilo-detail.html) | $9.877 |
| Alluminum base for T8 Nut | [cnc ciensia](https://www.instagram.com/cnc.ciensa/) | $25.000  |
| couple 5mm->8mm | [vistronica](https://www.vistronica.com/acoplamiento-para-eje/) | $4.572 |
| 3d printed motor base | [cnc ciensia](https://www.instagram.com/cnc.ciensa/) | $30.000 |

**Send cost**: $8.500

**Total**: $294.870
## Mechanic:
| Name | Provider | Pricing (COP) |
| ------------- | ------------- |  ------------- |
|Acrilic 4mm (Base) 6mm (Mobile hand) | [mercadolibre](https://articulo.mercadolibre.com.co/MCO-466571454-lamina-de-acrilico-transparente-en-5-mm-de-90cms-x-12m-_JM?quantity=1#position=3&type=item&tracking_id=11bda8ff-7e99-4d0a-b1df-c3f8d93fd9de) | $219.000 |
|screws and nuts | []() | $20.000 |
|Laser cutting (30 Min) | [cnc ciensia](https://www.instagram.com/cnc.ciensa/) | $ |

**Total**: $294.870
## Neumatic:
| Name | Provider | Pricing (COP) |
| ------------- | ------------- |  ------------- |
| Ambu 800cm^3 | [mercadolibre](https://articulo.mercadolibre.com.co/MCO-453482344-resucitador-adulto-ambu-mark-iv-_JM?quantity=1#position=14&type=item&tracking_id=84b0efee-bfa2-4141-9a3f-29b9adb6abbb)  | $1'012.000 |
| Syringe | Local pharmacy  | $2.000 |

**Total**: $

## Total cost
**Aprox** (Electric - Mechanic - Neumatic): $

# Team
## Salvarting
* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050477)
* **Yersson Ramiro Carrillo Amado** - [*GitHub*](https://github.com/yercar18) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0001637655)
* **Brayam Steven caicedo florez**  - [*GitHub*]() - [CV]()
* **Carlos Mauricio Pallares Carrillo**  - [*GitHub*]() - [CV]()
* **Pedro Jesús Gonzalez Torres** - [*GitHub*]() - [CV]()
* **Cesar Salazar Paez.** - [*GitHub*]() - [CV]()
* **Yeison Ferney Osorio buitrago** - [*GitHub*]() - [CV]()
* **Alber Iván Sánchez Álvarez** - [*GitHub*]() - [CV]()
* **Juan Enrique Vargas López** - [*GitHub*]() - [CV]()
* **Johan jazer orduz Molina** - [*GitHub*]() - [CV]()

![Salvarting](https://lh3.googleusercontent.com/AzuH3jOi5ijnEcBDfXqL9HO_dPtBWpY2o58rWW1Xs_0ZaDoCeQ3xv360V7CZS7bsBUqv0pDOposgkDT3DAi3yIPqlXZP7J1HyBVd-t-to11igDhemcz5UUPSBZnqGLU42xnTKCZJpqrAlS0BhXmNHU1_EvFbg_bI5e_7AJx1lK5m9I7xtGxhTFvkI-zklvQf-6Z7U1L5KZBkmRg-JPZFk8UC5Ya-2qhQrEqKgbY-1Md4UCZd68lofqCBUZvTWCyD6wAxPec3V3orE-1dGjDgIlzIy4jSBaJW5LoNbydOVX07a7PGOYYdLXv7eSfOCAw7tAxD3zSKpzNdMdhiqvDPTZ0lburtJx6bjczDjIFSIoI5KIiVG_KiXXX6EAqbD7morxt3GX5E4REXdMfpl62sb_R9vdzUF4ae9oKkikAZTiikukzlVI05N4iLpUsKOHRKKVzFCt5JrIy-TXJ2qG0tDsCLQXNdKIsNCkHGnROc4McGRKQlU4DOxNewBHJeVlQmZALjLfw23fuDTYy1m2x9ZrLUxmApKCXLTusb90rSfdJ_bDuBUlIT9jq2ecbUUrIQgrE-twAkozCFi6JfoBu-d6hNE7kfJ7mHlt26OZwY_WbLxKBbv5jtsqn6omjIs0wQgbWF27glJMZxitQbUY7m5two3oGTVWC_ZKyezbhasqG5bR9WKMJPT5yiXYzc1IxHUZ6u=w1366-h621-ft)

# Partners
* **[CNC Ciensia](https://www.instagram.com/cnc.ciensa/)**
* **[Vistronica](https://www.vistronica.com/)**
<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/miguel5612/Arduino_Respirator.svg?style=flat-square
[contributors-url]: https://github.com/miguel5612/Arduino_Respirator/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/miguel5612/Arduino_Respirator.svg?style=flat-square
[forks-url]: https://github.com/miguel5612/Arduino_Respirator/network/members
[stars-shield]: https://img.shields.io/github/stars/miguel5612/Arduino_Respirator.svg?style=flat-square
[stars-url]: https://github.com/miguel5612/Arduino_Respirator/stargazers
[issues-shield]: https://img.shields.io/github/issues/miguel5612/Arduino_Respirator.svg?style=flat-square
[issues-url]: https://github.com/miguel5612/Arduino_Respirator/issues
[license-shield]: https://img.shields.io/github/license/miguel5612/Arduino_Respirator.svg?style=flat-square
[license-url]: https://github.com/miguel5612/Arduino_Respirator/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[build-url]: https://travis-ci.org/dwyl/esta.svg?branch=master
[linkedin-url]: https://www.linkedin.com/in/miguel5612
[product-screenshot]: images/screenshot.png
