# Commercial Program

## Motivation
This program is a C++ application to manage commercial transactions.
It handles the interaction between buyers and products, and can keep the history of all the transactions. 

## Installation

The simplest way to build the code is by using Qt Creator. You can also download the Qt library manually from the website and edit the Makefile correctly.

## Usage

Enter to the program by entering the code. The default code is "huji".

<img src="https://user-images.githubusercontent.com/69756617/205748445-1a408a35-2e52-44ea-9a05-35d87155b0a4.PNG"/>

<img src="https://user-images.githubusercontent.com/69756617/205748880-9874e17e-55c9-4bbf-a95e-ccab7261dd10.png"/>

<img src="https://user-images.githubusercontent.com/69756617/205748470-376ae427-704a-4a85-bb86-7a90332078f2.PNG"/>

<img src="https://user-images.githubusercontent.com/69756617/205748457-444077c3-41c7-4170-a70a-df1ada4b5ac8.PNG"/>

<img src="https://user-images.githubusercontent.com/69756617/205748481-dcb405ce-16ce-41dd-a99b-9c024f3544d0.PNG"/>



The main window is divided in two parts: the encryption secion and the decryption section. Type a text in the first section and press "ENCRYPT" to generate the code associated to your text (special characters, capital letters and numbers are not supported in this version).

<img src="https://user-images.githubusercontent.com/69756617/205722170-120ba09d-36dc-464f-8aff-c5fd1487bc7a.PNG"/>

Each letter is translated to its numerical value, and then shifted according to the coding key.

<img src="https://user-images.githubusercontent.com/69756617/205722708-1ee16109-280b-4c3d-94b8-36cb2d9a1549.PNG"/>

By using the same code in the decryption section, you can retrieve the original text.

<img src="https://user-images.githubusercontent.com/69756617/205722143-cc19d796-c007-47a1-ad17-9b13b8e79354.PNG"/>

You can also use a special key by checking the box. The generating code will be different according to the special key you are using.

<img src="https://user-images.githubusercontent.com/69756617/205722206-ba0c0903-d3d4-479c-a769-02a5a4c89bde.PNG"/>

Note that if you try to decrypt a code with a different key than the key used to encrypt the text, you will not be able to retrieve the original text (unless you guess the special key).

<img src="https://user-images.githubusercontent.com/69756617/205722228-f0b8a439-5e44-4f74-9386-a7f28e0b14b9.PNG"/>


