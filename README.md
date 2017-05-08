Ola.

Amanhã teremos o meetup. Para os que forem levar computador para seguir as apresentações com mão na massa, aqui está os requerimentos para instalar, para que possam faze-lo antes já que na UFU a internet não funciona.


## Integração Python + C

Os arquivos de exemplo estão nesse repositório:
https://github.com/PythonTriangulo/4meetup

A apresentação pode ser baixada aqui:
https://github.com/PythonTriangulo/4meetup/raw/master/python%2Bc/apresentacao.pdf

Eles também podem ser baixados aqui:
https://github.com/PythonTriangulo/4meetup/raw/master/python%2Bc/CPython.zip

* `Python 3`
* Compilador de `C` (`GCC` ou `CLANG`)
* `Make`
* Muito recomendado: `Ipython3` (https://ipython.org/)

Para compilar os exemplos é necessário ter os cabeçarios C do Python.

Com apt (Ubuntu, Debian...):
`sudo apt-get install python-dev  # for python2.x installs`
`sudo apt-get install python3-dev  # for python3.x installs`

Com yum (Centos, Redhat, Fedora...):
`sudo yum install python-devel`


## Scraping HTML WEB Pages com LXML

*SLIDES: http://slides.com/allandaemon/lxml*

* a biblioteca `lxml`
* Muito recomendado: `Ipython` (https://ipython.org/)
* Bonus: `Selenium`



Instalando lxml: http://lxml.de/installation.html

Para maioria das pessoas um dos comandos serve:

`sudo apt install python-lxml python-lxml`
ou
`sudo pip install lxml`

Para o seleniumm, precisa instalar o pacote Python e um driver para algum navegador que queira usar (chrome, firefox, etc):
https://selenium-python.readthedocs.io/installation.html
