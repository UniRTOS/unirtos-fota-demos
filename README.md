# unirtos-fota-demos

[中文](README.zh.md) | English

This repository is recommended to be used via the unirtos-cli demo workflow to ensure consistent project creation, environment setup, and build processes.

## Overview

`unirtos-fota-demos` provides a comprehensive demonstration of FOTA (Firmware Over-The-Air) capabilities on UniRTOS.  
This directory focuses on remote firmware upgrade examples, covering typical scenarios from firmware download to upgrade flow integration, so you can quickly understand FOTA capability boundaries and choose the right transport protocol for your product.

FOTA is a core mechanism for remote firmware maintenance in embedded devices. UniRTOS provides a complete FOTA support framework that enables firmware package retrieval over multiple transport protocols (e.g., FTP, HTTP), and performs firmware replacement and reboot activation through a unified upgrade write interface. This directory provides multiple typical scenario examples for developers to reference and quickly integrate into their own product upgrade workflows.

## Feature Description

- Supports firmware download and upgrade via the **FTP** protocol (see [ftp-fota-demos](./ftp-fota-demos/))
- Supports firmware download and upgrade via the **HTTP** protocol (see [http-fota-demos](./http-fota-demos/))
- Covers the complete FOTA workflow: PDP activation → firmware download → write to FOTA module → result handling
- Each sub-demo can be compiled and run independently, with full error handling and log output
- Easily extensible to advanced scenarios: authenticated servers, resume-from-break, multi-version management, and production-grade upgrade orchestration

## Sub-Demo Overview

| Sub-Demo | Protocol | Description |
|---|---|---|
| [ftp-fota-demos](./ftp-fota-demos/) | FTP | Downloads firmware via FTP client; suitable for intranet or private server distribution |
| [http-fota-demos](./http-fota-demos/) | HTTP | Downloads firmware via HTTP GET with fixed-length and chunked transfer support; suitable for public OTA service distribution |

## Quick Start

### 1. Install the UniRTOS Toolchain

- [Development Preparation](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/开发准备/开发准备.html)
- [Install Cross-Compilation Toolchain](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/环境搭建/环境搭建.html)
- [Install Python3](https://www.python.org/downloads/)
- [Install git](https://git-scm.com)
- Install unirtos-cli: `pip install unirtos-cli`

After installation, verify the following commands are available:

```bash
python --version       # Python3
git --version
unirtos --version      # 1.0.5 or later
unirtos-cli version    # 1.0.11 or later
```

### 2. Create the Demo Project with unirtos-cli

List available demos and versions:

```bash
unirtos-cli ls-demos
```

Create the demo project:

```bash
unirtos-cli new -r unirtos-fota-demos
```

To specify a version:

```bash
unirtos-cli new -r unirtos-fota-demos -v 1.0.0
```

### 3. Enter the Sub-Demo Directory and Build

Choose the sub-demo for your preferred transport protocol. For example, HTTP FOTA:

```bash
cd unirtos-fota-demos-1.0.0/http-fota-demos
unirtos-cli env-setup
unirtos-cli build
```

FTP FOTA:

```bash
cd unirtos-fota-demos-1.0.0/ftp-fota-demos
unirtos-cli env-setup
unirtos-cli build
```

## Common Commands

```bash
# Open SDK menu configuration
unirtos-cli menuconfig

# Clean build artifacts
unirtos-cli clean
```

## Directory Structure

```
unirtos-fota-demos/
├── README.md
├── README.zh.md
├── ftp-fota-demos/                # FTP-based FOTA upgrade example
│   ├── CMakeLists.txt
│   ├── env_config.json
│   ├── ftp_fota_demo.c            # FTP firmware download and upgrade main logic
│   ├── ftp_fota_demo.h
│   ├── menuconfig/
│   ├── README.md
│   └── README.zh.md
└── http-fota-demos/               # HTTP-based FOTA upgrade example
    ├── CMakeLists.txt
    ├── env_config.json
    ├── http_fota_demo.c           # HTTP firmware download and upgrade main logic
    ├── http_fota_demo.h
    ├── menuconfig/
    ├── README.md
    └── README.zh.md
```

## Protocol Selection Guide

| Scenario | Recommended Solution |
|---|---|
| Device connects to a private FTP server in a controlled network | ftp-fota-demos |
| Device retrieves firmware from a public HTTP/HTTPS server | http-fota-demos |
| Resume-from-break (Range request) support needed | http-fota-demos (extensible) |
| Private service requiring username/password authentication | ftp-fota-demos (extensible) |

## Technical Community

Forum: https://forumschinese.quectel.com/c/66-category/66

## Contributing

Contributions are welcome. Please follow these guidelines:
- Run a basic validation before submitting: env-setup, build, clean.
- Use clear commit messages describing the purpose, scope of changes, and validation results.
- Update README and related documentation when adding features or changing behavior.
- Submit bug fixes and feature improvements via Issues or Pull Requests.
