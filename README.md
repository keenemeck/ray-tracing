<a name="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/keenemeck/ray-tracing">
    <img src="render.png" alt="Logo" width="208" height="117">
  </a>

<h3 align="center">Ray Tracing</h3>

  <p align="center">
    Implements ray tracing software, fully written in C++
    <br />
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

This project implements ray tracing software in C++ following the book, *Ray Tracing in One Weekend*, by Peter Shirley, Trevor David Black, and Steve Hollasch. 

### Built With

* [![Cpp][Cpp.com]][Cpp-url]


<!-- GETTING STARTED -->
## Getting Started

To run the ray tracer with default settings, follow the installation.

### Prerequisites

Requires a C++ compiler, version 11 or higher

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/keenemeck/ray-tracing.git
   ```
2. Change into the ray-tracing directory
   ```sh
   cd ray-tracing
   ```
3. Compile and run the program
   ```sh
   g++ -I include -std=c++11 cpp/*.cpp -o ../driver && .././driver > image.ppm
   ```


<!-- USAGE EXAMPLES -->
## Usage

To change the scene presented and camera settings, open the `driver.cpp` file located in `/cpp`, and change the camera settings to those desired.

The output will be written to `image.ppm`, in the repo's root directory.


<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Ray Tracing in One Weekend](https://github.com/RayTracing/raytracing.github.io/)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/keenemeck/ray-tracing.svg?style=for-the-badge
[contributors-url]: https://github.com/keenemeck/ray-tracing/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/keenemeck/ray-tracing.svg?style=for-the-badge
[forks-url]: https://github.com/keenemeck/ray-tracing/network/members
[stars-shield]: https://img.shields.io/github/stars/keenemeck/ray-tracing.svg?style=for-the-badge
[stars-url]: https://github.com/keenemeck/ray-tracing/stargazers
[issues-shield]: https://img.shields.io/github/issues/keenemeck/ray-tracing.svg?style=for-the-badge
[issues-url]: https://github.com/keenemeck/ray-tracing/issues
[license-shield]: https://img.shields.io/github/license/keenemeck/ray-tracing.svg?style=for-the-badge
[license-url]: https://github.com/keenemeck/ray-tracing/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/keenem
[product-screenshot]: render.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
[Cpp.com]: https://img.shields.io/badge/C++-00599C.svg?&style=for-the-badge&logo=cplusplus&logoColor=white
[Cpp-url]: https://isocpp.org
