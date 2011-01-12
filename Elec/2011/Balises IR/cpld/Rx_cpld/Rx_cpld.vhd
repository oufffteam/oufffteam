-- Auteur: P.P
-- Version: A
-- Date de cr�ation: 12/01/11

-- Description: Top level entity du CPLD de la balise Rx, fonctionne comme un mux pour s�lectionner un capteur parmis les 16 disponibles

LIBRARY IEEE;
	USE IEEE.STD_LOGIC_1164.ALL;
	USE IEEE.NUMERIC_STD.ALL;

ENTITY RX_cpld IS
	GENERIC 	();
	PORT		(	-- I/O G�n�riques
					CLK		: IN STD_LOGIC;
					-- TSOPs
					TSOP1		: IN STD_LOGIC_VECTOR (15 DOWNTO 0);
					TSOP2		: IN STD_LOGIC_VECTOR (15 DOWNTO 0);
					-- Xbee (v�rifier les IN/OUT)
					Xbee_dout	: IN STD_LOGIC;
					Xbee_din		: OUT STD_LOGIC;
					Xbee_dtr_b	: OUT STD_LOGIC;
					Xbee_cts_b	: IN STD_LOGIC;
					Xbee_rst_b	: OUT STD_LOGIC;
					Xbee_sleep_b: OUT STD_LOGIC;
					Xbee_rts_b	: OUT STD_LOGIC;
					-- PIC
					PIC_Rx1		: OUT STD_LOGIC;
					PIC_Tx1		: IN STD_LOGIC;
					PIC_Rx2		: OUT STD_LOGIC;
					PIC_Tx2		: IN STD_LOGIC;
					MODE_SELECT	: IN STD_LOGIC; -- mode de fonctionnement (soit gestion des TSOP soit gestion de la RF)
					ADR			: IN STD_LOGIC_VECTOR (3 DOWNTO 0)); -- selection d'adresses pour les TSOP
END ENTITY RX_cpld;


ARCHITECTURE basic_mux_RX_cpld OF RX_cpld IS



BEGIN

END ARCHITECTURE;