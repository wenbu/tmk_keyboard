void backlight_init_ports(void);

void backlight_init_pwm(void);
void backlight_set(uint8_t level);

void backlight_enable(void);
void backlight_disable(void);

void backlight_enable_r(void);
void backlight_enable_g(void);
void backlight_enable_b(void);
void backlight_disable_r(void);
void backlight_disable_g(void);
void backlight_disable_b(void);

void backlight_brighten(void);
void backlight_dim(void);