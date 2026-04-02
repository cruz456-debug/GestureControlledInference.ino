import cv2
import mediapipe as mp
import serial
import time

# Configuration Communication
try:
    ser = serial.Serial('COM3', 115200, timeout=1) # Ajuste le port COM
except:
    print("Erreur: Port série non trouvé.")

# Initialisation MediaPipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(static_image_mode=False, max_num_hands=1, min_detection_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

cap = cv2.VideoCapture(0)

while cap.isOpened():
    success, img = cap.read()
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)

    if results.multi_hand_landmarks:
        for hand_lms in results.multi_hand_landmarks:
            # Récupération du point 8 (index tip)
            # Normalisé entre 0.0 et 1.0
            pos_x = hand_lms.landmark[8].x
            
            # Mapping 0.0-1.0 vers 0-180 degrés (Inversé pour miroir)
            angle = int(180 - (pos_x * 180))
            
            # Envoi à l'ESP32
            ser.write(f"{angle}\n".encode())
            
            mp_draw.draw_landmarks(img, hand_lms, mp_hands.HAND_CONNECTIONS)

    cv2.imshow("IA Control Interface", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
