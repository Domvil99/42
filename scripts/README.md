# Scripts de apoyo para preparar `git push`

Contiene utilidades para inspeccionar cambios locales, compilar proyectos afectados, ejecutar Norminette/autofix cuando esté disponible y generar un plan de commits sugerido.

Archivos:
- `prepare_push.sh`: script principal. Ejecutarlo desde la raíz del repositorio:

```bash
bash scripts/prepare_push.sh
```

- `scripts/suggested_commits.txt` será generado por el script y contiene los comandos `git add`/`git commit` sugeridos agrupados por proyecto.

Recomendación de flujo local:
1. Ejecutar `bash scripts/prepare_push.sh`.
2. Revisar salidas de `make` y `norminette` y corregir errores.
3. Abrir `scripts/suggested_commits.txt`, aplicar `git add` y `git commit` por grupo.
4. Ejecutar tests locales relevantes en `tests/`.
5. Finalmente: `git push origin <branch>`.

Nota: Este script no hace `git push` automáticamente por seguridad.
