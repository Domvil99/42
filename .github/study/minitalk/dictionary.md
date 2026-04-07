# minitalk Dictionary

Glosario tecnico del proyecto con mini ejemplos.

## Signal
- Definicion: evento asincrono del sistema operativo.
- Mini ejemplo: `SIGUSR1` representa bit 1.

## SIGUSR1 / SIGUSR2
- Definicion: senales de usuario usadas como canal de datos.
- Mini ejemplo: `SIGUSR1`=1, `SIGUSR2`=0.

## PID
- Definicion: identificador unico de proceso.
- Mini ejemplo: cliente envia a PID mostrado por servidor.

## Bit serialization
- Definicion: enviar datos bit a bit en secuencia.
- Mini ejemplo: un byte requiere 8 senales.

## MSB / LSB
- Definicion: bit mas significativo / menos significativo.
- Mini ejemplo: envio de bit 7 a bit 0.

## ACK
- Definicion: confirmacion de recepcion.
- Mini ejemplo: server_bonus manda `SIGUSR1` tras cada bit.

## Signal handler
- Definicion: funcion llamada cuando llega una senal.
- Mini ejemplo: `handle_signal` reconstruye bytes.

## sigaction
- Definicion: API robusta para registrar handlers de senales.
- Mini ejemplo: permite obtener `si_pid` del emisor.

## sig_atomic_t
- Definicion: tipo seguro para acceso basico desde handlers.
- Mini ejemplo: flag de ACK en cliente bonus.

## Null terminator (`\0`)
- Definicion: byte cero que marca fin de string C.
- Mini ejemplo: cliente lo envia para cerrar mensaje.

## Race condition
- Definicion: comportamiento depende del timing entre procesos.
- Mini ejemplo: mandatory puede perder bits si ritmo es alto.

## IPC
- Definicion: comunicacion entre procesos.
- Mini ejemplo: minitalk implementa IPC solo con senales.

## Change Log

- 2026-04-05: glosario inicial de `minitalk`.
