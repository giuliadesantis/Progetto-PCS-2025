# Progetto PCS 2025  
**Autori:** Arianna Dho · Elena Damiani · Giulia De Santis  
**Anno accademico:** 2024 / 2025  
**Corso:** Programmazione e Calcolo Scientifico (Politecnico di Torino)


![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)  
![Languages: C++ & CMake](https://img.shields.io/badge/Languages-C++|CMake-yellow.svg)  

---

## 🧩 Descrizione del progetto  
Questo progetto è stato sviluppato nell’ambito del corso **Programmazione e Calcolo Scientifico (PCS)** del corso di laurea in Matematica per l'Ingegneria, con l’obiettivo di applicare tecniche di programmazione strutturata e scientifica in **C++**, utilizzando **CMake** per la gestione del build e la modularizzazione del codice.

Il software implementa un insieme di funzionalità per la rappresentazione e l’elaborazione di **solidi geodetici** a partire da solidi platonici, con particolare attenzione alla creazione, manipolazione ed esportazione dei risultati in formato  con .vtk per la visualizzazione tridimensionale tramite **ParaView**.

Il progetto si compone di due parti principali:
- Costruzione e analisi dei poliedri geodetici di classe I e dei loro duali.
- Estensione dell’algoritmo per la costruzione dei poliedri geodetici di classe II.

---

## 🧮 Fondamenti teorici

### 🔹 Solidi Platonici  
I solidi platonici sono poliedri convessi e regolari con facce congruenti e angoli equivalenti. Esistono solo cinque solidi platonici:

| Solido       | V (vertici) | E (spigoli) | F (facce) | Simbolo di Schläfli |
|---------------|-------------|--------------|-------------|----------------------|
| Tetraedro     | 4           | 6            | 4           | {3, 3}               |
| Cubo          | 8           | 12           | 6           | {4, 3}               |
| Ottaedro      | 6           | 12           | 8           | {3, 4}               |
| Dodecaedro    | 20          | 30           | 12          | {5, 3}               |
| Icosaedro     | 12          | 30           | 20          | {3, 5}               |

Il simbolo di Schläfli `{p, q}` indica un poliedro con facce p-gonali e q facce che si incontrano in ciascun vertice.

---

### 🔹 Poliedro duale  
Il **duale** di un poliedro si ottiene scambiando il ruolo di vertici e facce.  
- Cubo ↔ Ottaedro  
- Dodecaedro ↔ Icosaedro  
- Tetraedro ↔ Tetraedro (autoduale)

Il duale si costruisce unendo i baricentri delle facce adiacenti del poliedro originale.

---

### 🔹 Poliedri geodetici e duali  
Un **poliedro geodetico** è un poliedro convesso con facce triangolari che approssimano la superficie di una sfera.  
È definito dal simbolo `{3, q+}b,c`, dove:
- `{3, q}` è il simbolo di Schläfli del solido di partenza,  
- `b` e `c` rappresentano i parametri di triangolazione,  
- il simbolo `+` indica l’incremento della valenza (maggiore complessità geometrica).  

A seconda dei valori di `b` e `c`, si distinguono:
- **Classe I:** (b = 0, c ≥ 1) o (c = 0, b ≥ 1)  
- **Classe II:** (b = c ≥ 1)  

I vertici vengono poi proiettati sulla **sfera unitaria** centrata nell’origine, generando un modello sferico utilizzato in diversi ambiti (architettura, geodesia, chimica, modellazione molecolare).

---

## 🧱 Struttura dati e logica implementativa  
Ogni poliedro è descritto da una struttura gerarchica di **celle topologiche**:

- **Celle 0D (vertici):** coordinate (x, y, z) e identificativo univoco.  
- **Celle 1D (lati):** definite dagli ID dei vertici iniziale e finale.  
- **Celle 2D (facce):** definite da liste di vertici e lati ordinati.  
- **Celle 3D (poliedro):** insieme coerente di vertici, lati e facce.  

Le connessioni tra le celle rispettano la coerenza topologica:

```cpp
faces.edges[e].end == faces.edges[(e + 1) % E].origin;
faces.vertices[e] == faces.edges[e].origin;
```

---

## ⚙️ Il programma permette di:

- Generare **solidi platonici** (tetraedro, cubo, ottaedro, dodecaedro, icosaedro).
- Costruire **poliedri geodetici** di **classe I e II** a partire da parametri di input.
- Calcolare il poliedro **duale** di ciascun solido.
- Proiettare i vertici sulla sfera unitaria per ottenere modelli sferici realistici.
- Esportare i dati in file **.txt** e **.vtk**, visualizzabili con _ParaView_.
- Evidenziare **cammini minimi** tra due vertici specificati, calcolando distanza e numero di lati.
- Verificare la correttezza topologica della struttura dati (vertici, lati, facce, celle).
- Eseguire **test automatici** per validare le unità logiche (tramite _GoogleTest_).

---

## 🧱 Struttura del repository  
```
ProgettoPCS2025/
│
├── CMakeLists.txt         # File principale di configurazione del build
├── LICENSE                # Licenza GPL-3.0
├── README.md              # Descrizione del progetto
│
├── /Documentation          # Relazioni e documentazione tecnica
├── /ExportParaview         # Moduli per l’esportazione dei dati verso ParaView
├── /PlatonicSolid          # Implementazione delle classi dei solidi platonici
├── /src                    # Codice sorgente principale
└── /src_test               # Test di unità e validazione funzionale

```

---

## 💻 Tecnologie utilizzate  
- **Linguaggio:** C++ (standard ≥ C++17)  
- **Build system:** CMake  
- **Librerie:** Standard Template Library (STL)  
- **Output scientifico:** file `.vtk` per *ParaView*  
- **Compatibilità:** Linux, macOS, Windows  

---

## 🧰 Requisiti  
Assicurati di avere installato:  
- [CMake](https://cmake.org/) ≥ 3.16  
- Un compilatore C++ compatibile (es. `g++`, `clang++`, o `MSVC`)  
- [ParaView](https://www.paraview.org/) *(opzionale, per la visualizzazione 3D)*

---


## 📊 Esempio di risultato  
Ecco un esempio di esportazione visualizzata in ParaView:

![Esempio output ParaView](Documentation/example_paraview.png)

*(Figura: visualizzazione di un solido platonico esportato dal programma.)*

---

