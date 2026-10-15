#include "raylib.h"
#include <string>

// Estructura para manejar los botones de la interfaz gráfica
struct Button {
    Rectangle rect;
    std::string text;
    Color color;
    
    // Función auxiliar para detectar si el ratón está sobre el botón
    bool isHovered(Vector2 mouse) { 
        return CheckCollisionPointRec(mouse, rect); 
    }
};

int main() {
    // 1. Configuración inicial de la ventana gráfica
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Idle Miner: Camino a la Riqueza");
    SetTargetFPS(60);

    // 2. Variables de estado del juego (El "Core Loop")
    long long coins = 0;      // Moneda del juego
    int gems = 0;             // Moneda premium (micropagos)
    int clickPower = 1;       // Poder de recolección manual
    int autoMiners = 0;       // Recolección automática por segundo
    
    float timer = 0.0f;       // Temporizador para los cálculos de tiempo real

    // Definición geométrica de la interfaz (X, Y, Ancho, Alto)
    Button btnClick = { { 250, 200, 300, 100 }, "¡MINAR ORO!", GOLD };
    Button btnUpgrade = { { 50, 450, 200, 50 }, "Mejorar Pico (50 Oro)", ORANGE };
    Button btnAuto = { { 280, 450, 240, 50 }, "Minero Auto (150 Oro)", ORANGE };
    Button btnMicrotx = { { 550, 450, 200, 50 }, "Comprar 10 Gemas ($0.99)", LIME };

    // 3. El Game Loop Principal
    while (!WindowShouldClose()) {
        
        // --- ENTRADA Y LÓGICA DE ACTUALIZACIÓN ---
        Vector2 mousePoint = GetMousePosition();
        bool clicked = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // Mecánica adictiva: Los números suben solos (Minería automática)
        timer += GetFrameTime();
        if (timer >= 1.0f) {
            coins += autoMiners;
            timer = 0.0f;
        }

        // Interacciones del usuario
        if (clicked) {
            // Minería manual
            if (btnClick.isHovered(mousePoint)) {
                // Las gemas "premium" actúan como multiplicador para incentivar el pago
                coins += clickPower + (gems * 2); 
            }
            
            // Comprar mejoras con moneda del juego
            if (btnUpgrade.isHovered(mousePoint) && coins >= 50) {
                coins -= 50;
                clickPower += 1;
            }
            
            // Comprar automatización
            if (btnAuto.isHovered(mousePoint) && coins >= 150) {
                coins -= 150;
                autoMiners += 5;
            }
            
            // BOTÓN DE MICROPAGO (Simulación)
            if (btnMicrotx.isHovered(mousePoint)) {
                /* =========================================================
                   AQUÍ SE CONECTA LA PASARELA DE PAGOS REAL.
                   En un entorno de producción, este clic realizaría una
                   petición HTTP (POST) a tu servidor backend.
                   Tu servidor procesaría el pago con la API de Google Play, 
                   App Store o Stripe. Solo si el servidor responde "200 OK",
                   se otorgan las gemas. NUNCA se fía de la aplicación local.
                   ========================================================= */
                gems += 10; 
            }
        }

        // --- RENDERIZADO GRÁFICO (GPU) ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // HUD - Textos y Estadísticas en pantalla
        DrawText(TextFormat("Oro: %lld", coins), 20, 20, 30, DARKGRAY);
        DrawText(TextFormat("Gemas (Premium): %d", gems), 20, 60, 20, PURPLE);
        DrawText(TextFormat("Poder de clic: %d", clickPower), 550, 20, 20, DARKGRAY);
        DrawText(TextFormat("Oro / segundo: %d", autoMiners), 550, 50, 20, DARKGRAY);

        // Renderizado del botón principal (con efecto visual al pasar el ratón)
        Color clickColor = btnClick.isHovered(mousePoint) ? YELLOW : btnClick.color;
        DrawRectangleRec(btnClick.rect, clickColor);
        DrawText(btnClick.text.c_str(), btnClick.rect.x + 50, btnClick.rect.y + 35, 30, BLACK);

        // Renderizado de las tiendas
        DrawRectangleRec(btnUpgrade.rect, btnUpgrade.isHovered(mousePoint) ? RED : btnUpgrade.color);
        DrawText(btnUpgrade.text.c_str(), btnUpgrade.rect.x + 10, btnUpgrade.rect.y + 15, 15, WHITE);

        DrawRectangleRec(btnAuto.rect, btnAuto.isHovered(mousePoint) ? RED : btnAuto.color);
        DrawText(btnAuto.text.c_str(), btnAuto.rect.x + 15, btnAuto.rect.y + 15, 15, WHITE);

        DrawRectangleRec(btnMicrotx.rect, btnMicrotx.isHovered(mousePoint) ? GREEN : btnMicrotx.color);
        DrawText(btnMicrotx.text.c_str(), btnMicrotx.rect.x + 10, btnMicrotx.rect.y + 15, 15, BLACK);

        EndDrawing();
    }

    // 4. Limpieza de memoria
    CloseWindow();
    return 0;
}