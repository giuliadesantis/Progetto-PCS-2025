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
- **Build system:** CMake (versione ≥ 3.10)
- **Librerie:** 
  - Standard Template Library (STL)
  - Eigen3 (algebra lineare)
  - GoogleTest & GoogleMock (testing)
- **Output scientifico:** file `.vtk` per *ParaView*  
- **Compatibilità:** Linux, macOS, Windows  

---

## 🚀 Come compilare ed eseguire

### Prerequisiti
Prima di compilare, assicurati di avere installato:
- CMake (versione 3.10 o superiore)
- Un compilatore C++ con supporto C++17 (g++, clang++, MSVC)
- Eigen3
- GoogleTest e GoogleMock

#### Installazione dipendenze su Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install -y cmake build-essential libeigen3-dev libgtest-dev libgmock-dev
```

#### Installazione dipendenze su macOS:
```bash
brew install cmake eigen googletest
```

### Compilazione

1. **Clona il repository:**
```bash
git clone https://github.com/giuliadesantis/Progetto-PCS-2025.git
cd Progetto-PCS-2025
```

2. **Crea la directory di build:**
```bash
mkdir build
cd build
```

3. **Configura il progetto con CMake:**
```bash
cmake ..
```

4. **Compila:**
```bash
make -j$(nproc)  # Linux/macOS
# oppure
make -j4         # usa 4 core
```

### Esecuzione

#### Esegui il programma principale:
```bash
./ProgettoPCS2025 p q b c [v0 v1]
```

**Parametri:**
- `p` e `q`: simbolo di Schläfli `{p,q}` del solido platonico
- `b` e `c`: parametri di triangolazione (classe I: b=0 o c=0; classe II: b=c)
- `v0` e `v1` (opzionali): vertici per calcolare il cammino minimo

**Esempi:**
```bash
# Genera un icosaedro geodetico di classe I
./ProgettoPCS2025 3 5 0 2

# Genera un tetraedro con calcolo del percorso tra vertici 0 e 2
./ProgettoPCS2025 3 3 0 1 0 2
```

#### Esegui i test:
```bash
./ProgettoPCS2025_TEST
```

### Visualizzazione con ParaView
I file `.vtk` generati possono essere visualizzati con ParaView:
1. Apri ParaView
2. File → Open → seleziona il file `.vtk` generato
3. Clicca su "Apply" per visualizzare il modello 3D

---

## 🤝 Come contribuire

Leggi il file [CONTRIBUTING.md](CONTRIBUTING.md) per le linee guida su come contribuire al progetto.

---

## 📝 Changelog

Vedi [CHANGELOG.md](CHANGELOG.md) per la lista completa delle modifiche.

---
