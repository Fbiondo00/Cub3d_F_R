# cub3D

![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=white) ![MiniLibX](https://img.shields.io/badge/MiniLibX-555555?style=flat-square) ![42 Roma Luiss](https://img.shields.io/badge/42_Roma_Luiss-000000?style=flat-square&logo=42&logoColor=white)

A first-person 3D maze in the style of Wolfenstein 3D, rendered with **raycasting** (DDA) on top of MiniLibX.

Pair project at 42 Roma Luiss.

## Features

- Raycasting with the **DDA algorithm**, with a different wall texture for each side (N/S/E/W)
- Floor and ceiling colours set from the scene file
- Strict parser for `.cub` files: textures, colours and a map that must be closed by walls
- Movement with `W A S D`, rotation with `←` `→` and the **mouse**
- Builds on both **macOS** and **Linux**

## Build & run

```bash
make
./cub3d assets/maps/1.cub
```

## Scene file

```
NO ./assets/images/north.xpm
SO ./assets/images/south.xpm
WE ./assets/images/west.xpm
EA ./assets/images/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

---

<sub>Part of my 42 Roma Luiss curriculum · [more projects](https://github.com/Fbiondo00) · MIT License</sub>
