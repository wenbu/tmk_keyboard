typedef struct color_t color_t;

struct color_t {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

void backlight_init(void);

void backlight_set(color_t level);

void backlight_enable(void);
void backlight_disable(void);

void backlight_brighten(void);
void backlight_dim(void);
