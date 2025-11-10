# Changelog

Tutte le modifiche degne di nota a questo progetto verranno documentate in questo file.

Il formato è basato su [Keep a Changelog](https://keepachangelog.com/it/1.0.0/),
e questo progetto aderisce al [Semantic Versioning](https://semver.org/lang/it/).

## [1.0.0] - 2025

### Aggiunto
- Costruzione e analisi dei poliedri geodetici di classe I e dei loro duali
- Estensione dell'algoritmo per la costruzione dei poliedri geodetici di classe II
- Esportazione in formato VTK per visualizzazione con ParaView
- Calcolo di cammini minimi tra vertici
- Test automatici con GoogleTest
- Supporto per solidi platonici: tetraedro, cubo, ottaedro, dodecaedro, icosaedro
- Proiezione dei vertici sulla sfera unitaria

### Modifiche apportate per migliorare il progetto
- Aggiornato CMakeLists.txt per risolvere warning di deprecazione (CMake >= 3.10)
- Migliorato .gitignore per escludere artefatti di build
- Aggiunto GitHub Actions workflow per CI/CD
- Aggiunto CONTRIBUTING.md con linee guida per i contributi
- Aggiunto questo CHANGELOG.md

## Tipologie di modifiche
- `Aggiunto` per nuove funzionalità
- `Modificato` per modifiche a funzionalità esistenti
- `Deprecato` per funzionalità che verranno rimosse nelle prossime release
- `Rimosso` per funzionalità rimosse
- `Corretto` per bug fix
- `Sicurezza` in caso di vulnerabilità
