# Linee guida per contribuire

Grazie per il tuo interesse nel contribuire a questo progetto! 🎉

## Come contribuire

### Segnalare bug
Se trovi un bug, apri una [Issue](https://github.com/giuliadesantis/Progetto-PCS-2025/issues) con:
- Descrizione chiara del problema
- Passi per riprodurlo
- Comportamento atteso vs. comportamento osservato
- Ambiente (OS, versione di CMake, etc.)

### Proporre nuove funzionalità
Apri una Issue per discutere la tua proposta prima di iniziare a lavorarci.

### Inviare modifiche

1. **Fork** del repository
2. **Crea un branch** per la tua feature (`git checkout -b feature/nome-feature`)
3. **Scrivi codice** seguendo le linee guida di stile
4. **Esegui i test** per assicurarti che tutto funzioni
5. **Commit** delle modifiche (`git commit -m 'Aggiunge nuova feature'`)
6. **Push** al branch (`git push origin feature/nome-feature`)
7. Apri una **Pull Request**

## Linee guida di codifica

### C++ Style Guide
- Usa C++17 o superiore
- Evita `using namespace` nei file header (.hpp)
- Usa nomi descrittivi per variabili e funzioni
- Commenta il codice complesso
- Mantieni le funzioni concise e focalizzate

### Testing
- Aggiungi test per le nuove funzionalità
- Assicurati che tutti i test esistenti passino
- I test sono scritti usando Google Test

### Build
```bash
# Configura il progetto
mkdir build && cd build
cmake ..

# Compila
make

# Esegui i test
./ProgettoPCS2025_TEST
```

## Processo di review

Le Pull Request verranno revisionate da almeno un maintainer. Potremmo richiedere modifiche prima dell'approvazione.

## Codice di condotta

Mantieni un comportamento rispettoso e professionale in tutte le interazioni.

## Domande?

Non esitare a chiedere aprendo una Issue!
