<p align="center">
    <h1 align="center">INCEPTION</h1>
</p>
<p align="center">
    <em>Streamline WordPress deployment with Inception's powerful orchestration!</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/mourdani/inception?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/mourdani/inception?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/mourdani/inception?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/mourdani/inception?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with the software and tools below.</em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/.ENV-ECD53F.svg?style=flat&logo=dotenv&logoColor=black" alt=".ENV">
	<img src="https://img.shields.io/badge/YAML-CB171E.svg?style=flat&logo=YAML&logoColor=white" alt="YAML">
	<img src="https://img.shields.io/badge/Docker-2496ED.svg?style=flat&logo=Docker&logoColor=white" alt="Docker">
	<img src="https://img.shields.io/badge/WordPress-21759B.svg?style=flat&logo=WordPress&logoColor=white" alt="WordPress">
	<img src="https://img.shields.io/badge/NGINX-009639.svg?style=flat&logo=NGINX&logoColor=white" alt="NGINX">
	<img src="https://img.shields.io/badge/MariaDB-003545.svg?style=flat&logo=MariaDB&logoColor=white" alt="MariaDB">
</p>
<hr>

##  Quick Links

> - [ Overview](#-overview)
> - [ Repository Structure](#-repository-structure)
> - [ Modules](#-modules)
> - [ Getting Started](#-getting-started)

---

##  Overview

The inception project orchestrates Docker containers for Nginx, MariaDB, and Wordpress through a Makefile, enabling seamless building, starting, stopping, and cleanup operations. With configurations like `docker-compose.yml` for Nginx, `.env` for MySQL and server settings, and a WordPress Dockerfile in `srcs/requirements/wordpress`, the project facilitates secure and optimized deployment of WordPress on `mourdani.42.fr`. This streamlined setup ensures efficient server management and database configuration for a robust WordPress instance.

---

##  Repository Structure

```sh
└── inception/
    ├── Makefile
    ├── README.md
    └── srcs
        ├── .env
        ├── docker-compose.yml
        └── requirements
            ├── mariadb
            │   ├── .dockerignore
            │   ├── .env.mariadb
            │   ├── Dockerfile
            │   └── conf
            │       └── 50-server.cnf
            ├── nginx
            │   ├── .dockerignore
            │   ├── .env.nginx
            │   ├── Dockerfile
            │   ├── conf
            │   │   └── nginx.conf
            │   └── tools
            │       ├── mourdani.42.fr.crt
            │       └── mourdani.42.fr.key
            └── wordpress
                ├── .dockerignore
                ├── .env.wordpress
                ├── Dockerfile
                └── conf
                    ├── php.ini
                    └── www.conf
```

---

##  Modules

<details closed><summary>.</summary>

| File                                                                   | Summary                                                                                                                                                                                             |
| ---                                                                    | ---                                                                                                                                                                                                 |
| [Makefile](https://github.com/mourdani/inception/blob/master/Makefile) | The Makefile in the `inception` repository orchestrates Docker containers for Nginx, MariaDB, and Wordpress. It provides commands for building, starting, stopping, and cleaning up the containers. |

</details>

<details closed><summary>srcs</summary>

| File                                                                                            | Summary                                                                                                                                                                                                 |
| ---                                                                                             | ---                                                                                                                                                                                                     |
| [docker-compose.yml](https://github.com/mourdani/inception/blob/master/srcs/docker-compose.yml) | Code Summary:**The code snippet in **srcs/docker-compose.yml** defines a service for Nginx in the main repository **inception**. Its role is to configure and build the Nginx container for deployment. |
| [.env](https://github.com/mourdani/inception/blob/master/srcs/.env)                             | Code snippet in `srcs/.env` sets MySQL and server configurations for WordPress deployment in `inception` repository. Ensures secure and optimized database and server setup for `mourdani.42.fr`.       |

</details>

<details closed><summary>srcs.requirements.wordpress</summary>

| File                                                                                                           | Summary                                                                                                                                                                                                                                                   |
| ---                                                                                                            | ---                                                                                                                                                                                                                                                       |
| [Dockerfile](https://github.com/mourdani/inception/blob/master/srcs/requirements/wordpress/Dockerfile)         |  WordPress Dockerfile for Inception Repository **Features:** Installs WordPress on Debian, configures PHP-FPM, and exposes ports for PHP and MySQL. **Reference:** `srcs/requirements/wordpress/Dockerfile` in `inception` Repository.             |
| [.env.wordpress](https://github.com/mourdani/inception/blob/master/srcs/requirements/wordpress/.env.wordpress) | inception/srcs/requirements/wordpress/.env.wordpress` sets WordPress environment variables for database connections and user credentials. It establishes key configurations for the WordPress instance in the repository's architecture. |

</details>

<details closed><summary>srcs.requirements.wordpress.conf</summary>

| File                                                                                                    | Summary                                                                                                                                                                                    |
| ---                                                                                                     | ---                                                                                                                                                                                        |
| [www.conf](https://github.com/mourdani/inception/blob/master/srcs/requirements/wordpress/conf/www.conf) | Code snippet in `www.conf` initializes a new pool in WordPress environment. Critical role in managing PHP processes for improved performance in parent repository architecture. |

</details>

<details closed><summary>srcs.requirements.nginx</summary>

| File                                                                                               | Summary                                                                                                                                                                                                         |
| ---                                                                                                | ---                                                                                                                                                                                                             |
| [.env.nginx](https://github.com/mourdani/inception/blob/master/srcs/requirements/nginx/.env.nginx) | Code in srcs/requirements/nginx/.env.nginx manages environment variables for the Nginx container in the repository. It configures settings and behavior specific to Nginx's deployment within the architecture. |

</details>

<details closed><summary>srcs.requirements.nginx.conf</summary>

| File                                                                                                    | Summary                                                                                                                                                                                                                              |
| ---                                                                                                     | ---                                                                                                                                                                                                                                  |
| [nginx.conf](https://github.com/mourdani/inception/blob/master/srcs/requirements/nginx/conf/nginx.conf) | `Code in srcs/requirements/nginx/Dockerfile sets up Nginx configuration for the Docker container in the project architecture, delivering web server functionalities. Key for serving static and dynamic content.` |

</details>

<details closed><summary>srcs.requirements.mariadb</summary>

| File                                                                                                     | Summary                                                                                                                                                                                                          |
| ---                                                                                                      | ---                                                                                                                                                                                                              |
| [Dockerfile](https://github.com/mourdani/inception/blob/master/srcs/requirements/mariadb/Dockerfile)     | Code snippet in `srcs/requirements/mariadb/Dockerfile` sets up MariaDB in the repository by updating and installing mariadb-server, configuring the server, exposing port 3306, and starting the mariadb daemon. |
| [.env.mariadb](https://github.com/mourdani/inception/blob/master/srcs/requirements/mariadb/.env.mariadb) | Code snippet at srcs/requirements/mariadb/.env.mariadb sets MySQL configuration with root password, database name, user, and password for the Inception repository's MariaDB container.                          |

</details>

<details closed><summary>srcs.requirements.mariadb.conf</summary>

| File                                                                                                            | Summary                                                                                                                                                                                             |
| ---                                                                                                             | ---                                                                                                                                                                                                 |
| [50-server.cnf](https://github.com/mourdani/inception/blob/master/srcs/requirements/mariadb/conf/50-server.cnf) | Code in srcs/requirements/mariadb/conf/50-server.cnf sets configuration options for MariaDB server, ensuring optimal performance and stability within the repository's Docker-based infrastructure. |

</details>

---

##  Getting Started

***Requirements***

Ensure you have the following dependencies installed on your system:

* **<code>► Docker</code>**:
* **<code>► Docker-compose</code>**:
* **<code>► Git</code>**:

###  Running inception

1. Clone the inception repository:

```sh
git clone https://github.com/mourdani/inception
```

2. Change to the project directory:

```sh
cd inception
```

Use the following command to run inception:

```sh
docker compose up
```
