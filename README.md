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

# Arduino Low Cost Ventilator
Arduino low cost respirator to assist coronavirus crisis.

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Getting Started](#Getting-Started)
  * [Objective](#Objective)
  * [Result](#result)
  * [Legal framework](#Legal)
* [List of Materials](#Materials)
* [Wiring](#Wiring)
  * [Sensors](#Sensors)
  * [Arduino](#Arduino)
  * [ESP8266](#ESP8266)
* [Documentation](#Documentation)
* [Sensor manufacturers](#Sensor-manufacturers)
* [Contributing](#Contributing)
* [Authors](#TEAM)
* [Partners](#Partners)
# Getting-Started
* Buy the materials.
* Construct your mechanical and neumatic system.
* Connect the electrical components.
* Test your mechanical work to check his functionality.
* Download the code and program.
  * First load each test on test folder to try individually the components and check his work.
  * If the interface will be via serial port program [OpenSourceVentilatorSerial](https://github.com/miguel5612/Arduino_Respirator/blob/master/OpenSourceVentilatorSerial/OpenSourceVentilatorSerial.ino)
  * In case you have an ESP8266 and want to control it via Wi-Fi connect your ESP-8266 to the arduino and load the ESP-8266 code together with the [OpenSourceVentilatorSerial](https://github.com/miguel5612/Arduino_Respirator/blob/master/OpenSourceVentilatorSerial/OpenSourceVentilatorSerial.ino) code
## Objective
To design a low cost/ high sofisticated respirator using local materials
## Result
![Result 04.04.2020](https://lh3.googleusercontent.com/74NNB0H3t6N-1nOT1vsUdLlPNlwFXykKHZkd4GFfzxG98wrrTX6rUB_0DXySXwOmhQjdTdcqEWCL1JVKhYL1tkzzZi3m95fB6Z5KyTCcldp7wnhxHnuI5DPztQaGmsJ4wwdi_v7ljeAomFtpV-eLrwcQfOwIAzOwz9Ev4EI4Gor0Y-9Qcaw3exYhGfKOqsiPQ5_vbXQDXqlfPbmvsOzri2Ko6WUDGjm-OglGtqqYEPA7lnrCuxn_QIv2r2eg243Wym_rBnNORybEz6VmJ-jMGeU0jZpTQesEjkr_JO6XRMKCYin33snbViC5A3elH5Im7TbpozvPq8AWY2HDQ-vIaNXoB1AkwYXvmX47ZCP2w2jDiyP71yk7EKMVQ6w7UpsBQ5B4FjAc9CYgcGcLbKHj2wyWMxyxxJ1VNXOuPkLBs3FUIxWNnrOfTwNBmvSjyQionCxbtLObo90iOidhgb0VEmPKS9SdbEA6ga0T-G6bXn3fQwTLUveDaWLV367CIpXRi-FIi-B31dvX76I80rHdNxtNsepRzDx5HVSpEjdmTlC7J8x90VJGtN9r_2Y4cUzwI6RPMBLRKvW4w9zqWPSVk9mH_SYFdvwLnc4cnAcF7kikSuz53WgQGyT1s4zYBkw25W9DsoMKz7rZLi7W_kEobJ-bggXOUu8QfkM3UG6M_JgBAcZ0YR9vkSNA5gDoXCATvfpH=w1366-h621-ft)
## Legal
**Note**: In spanish because is transcribed from the Colombian regulations
* **[evaluation of medical device in colombia](https://www.invima.gov.co/dispositivos-medicos-y-equipos-biomedicos)**

#### Entity: Invima
#### Params
* Description
* Tecnicall studies and results
* method of sterilization
* Final Disposal
* Risk Analisis
* Security Analisis
* Clinical studies
* User manual (Spanish)

* **[Resolucion 522 de 2020](https://www.minsalud.gov.co/Normatividad_Nuevo/Resoluci%C3%B3n%20No.%20522%20de%202020.pdf)** 

* **[Clasificacion de dispositivos medicos](https://www.invima.gov.co/documents/20143/442916/abc_dispositivos-medicos.pdf/d32f6922-0c50-bcaa-6b53-066edfb98274)** 

#### Clasification: IIb (C) Riesgo Alto Ventilador pulmonar / implantes ortopédicos.
#### Time to get an invima certification 90 days after radication.

* **[ley 434 de 2001](http://legal.legis.com.co/document/Index?obra=legcol&document=legcol_75992041b795f034e0430a010151f034)**

Dispositivo y equipo biomédico. Cualquier instrumento, aparato, artefacto, equipo u otro artículo, utilizado sólo o en combinación incluyendo sus componentes, partes accesorios y programas informáticos que intervengan en su buen funcionamiento, fabricado, vendido o recomendado para uso en:
1. Diagnóstico, control, tratamiento curativo o paliativo, alivio o compensación de una lesión o una deficiencia, o prevención de una enfermedad, trastorno o estado físico anormal o sus síntomas, en un ser humano.

2. Investigación, sustitución o modificación de la anatomía o de un proceso fisiológico.

3. Restauración, corrección o modificación de una función fisiológica o estructura de un ser humano;

4. Diagnóstico del embarazo en un ser humano;

5. Cuidado de seres humanos durante el embarazo o el nacimiento. O después del mismo, incluyendo el cuidado del recién nacido.

##### Laboratory required by regulation:
##### Equipment required by the standard:
##### Variables to be measured or quantitative indicators:
##### Expected result:

* **[Decreto 4725 de 2005](https://www.who.int/medical_devices/survey_resources/health_technology_national_policy_colombia.pdf)**

Es importante contar con Registro por parte del Invima para comercializar un producto porque a través del Registro Sanitario o permiso de comercialización, el Invima garantiza que la introducción de los dispositivos médicos y equipos biomédicos, cumplan con los estándares de seguridad, eficacia y desempeño para que puedan ser comercializado y usados en Colombia.


##### Laboratory required by regulation:
##### Equipment required by the standard:
##### Variables to be measured or quantitative indicators:
##### Expected result:

* **[Resolucion 4816 de 2008](http://www.saludcapital.gov.co/sitios/VigilanciaSaludPublica/Todo%20IIH/Resoluci%C3%B3n%204816%20de%202008.pdf)**

Los fabricantes e importadores de dispositivos médicos de uso en humanos. 

##### Laboratory required by regulation:
##### Equipment required by the standard:
##### Variables to be measured or quantitative indicators:
##### Expected result:

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
| screw | [vistronica](https://www.vistronica.com/#q=varilla%20roscada%20&from_user=&page=0&refinements=%5B%5D&numerics_refinements=%7B%7D&index_name=%22prestashop2_all_es%22) | $25.185 |
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

# Documentation

### Initial presentation (29.03.2020)
[view](https://drive.google.com/open?id=1U2AUueaFD7FKk89XvETDbtZuPM2e4Z0P)

# Team
## Salvarting
* **Miguel A. Califa U.** - [*GitHub*](https://github.com/miguel5612) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0000050477)
* **Yersson Ramiro Carrillo Amado** - [*GitHub*](https://github.com/yercar18) - [CV](https://scienti.colciencias.gov.co/cvlac/visualizador/generarCurriculoCv.do?cod_rh=0001637655)
* **Brayam Steven caicedo florez**  - [*GitHub*]() - [CV]()
* **Nelson Beltrán Galvis** - [*GitHub*]() - [CV]()
* **Carlos Mauricio Pallares Carrillo**  - [*GitHub*]() - [CV]()
* **Pedro Jesús Gonzalez Torres** - [*GitHub*]() - [CV]()
* **Cesar Salazar Paez.** - [*GitHub*]() - [CV]()
* **Yeison Ferney Osorio buitrago** - [*GitHub*]() - [CV]()
* **Alber Iván Sánchez Álvarez** - [*GitHub*]() - [CV]()
* **Juan Enrique Vargas López** - [*GitHub*]() - [CV]()
* **Johan Jazer Orduz Molina** - [*GitHub*]() - [CV]()
* **Juan Carlos Vergel** - [*GitHub*]() - [CV]()
* **Gabriel Eusse** - [*GitHub*]() - [CV]()

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
