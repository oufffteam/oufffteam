library ieee ;
use ieee.std_logic_1164.all ;
use ieee.std_logic_arith.all ;
use ieee.std_logic_unsigned.all ;

entity TB_gh_baud_rate_gen is

end entity;

architecture TB_gh_baud_rate_gen_arch of TB_gh_baud_rate_gen is

	component gh_baud_rate_gen is
		port(
			clk     : in std_logic;	
			BR_clk  : in std_logic;
			rst     : in std_logic;
			WR      : in std_logic;
			BE      : in std_logic_vector (1 downto 0); -- byte enable
			D       : in std_logic_vector (15 downto 0);
			RD      : out std_logic_vector (15 downto 0);
			rCE     : out std_logic;
			rCLK    : out std_logic
			);
	end component;

	signal clock_in	: std_logic;
	signal clock_BR	: std_logic;
	signal reset	: std_logic;
	signal WR      	: std_logic;
	signal BE       : std_logic_vector (1 downto 0); -- byte enable
	signal D        : std_logic_vector (15 downto 0);
	signal RD       : std_logic_vector (15 downto 0);
	signal rCE      : std_logic;
	signal rCLK     : std_logic;
	
	constant period		: time := 33 ns;
	constant period_BR	: time := 55 ns;
	
	begin
	
	main_horloge : process
		begin
			clock_in <= '1';
			wait for period/2;
			clock_in <= '0';
			wait for period/2;		
	end process main_horloge;
	
	horloge_BR : process
		begin
			clock_BR <= '1';
			wait for period_BR/2;
			clock_BR <= '0';
			wait for period_BR/2;		
	end process horloge_BR;
	
	UUT: gh_baud_rate_gen 
		port map (
			clk		=> clock_in,
			BR_clk  => clock_BR,
			rst     => reset,
			WR		=> WR,
			BE      => BE,
			D       => D,
			RD      => RD,
			rCE     => rCE,
			rCLK    => rCLK);
			
	bench: process 
		begin
			reset 	<= '1';
			BE		<= "11";
			D		<= "0000000000000001";
			WR		<= '0';
			wait for 100 ns;
			reset <= '0';
			wait for 100 ns;
			WR	<= '1';
			wait for period;
			WR	<= '0';
			
			wait;
			
	end process;
	
	
end architecture;