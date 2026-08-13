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
