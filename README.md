# GestureControlledInference.ino
# AI-Powered Gesture Controlled Robotic Arm
**Système de Robotique Collaborative et Vision par Ordinateur**

## Présentation
Ce projet implémente une interface homme-machine (HMI) avancée permettant de piloter un bras robotique articulé par reconnaissance gestuelle. Le système utilise un pipeline d'IA distribué : le traitement de la vision est déporté sur une station de calcul, tandis que la cinématique et le contrôle des servomoteurs sont gérés en local par un microcontrôleur.

## Architecture du Système
* **Couche Vision (IA) :** Script Python utilisant **OpenCV** et **MediaPipe** pour le tracking 2D/3D des articulations de la main (21 points de repère).
* **Couche Communication :** Protocole série haute vitesse (115200 bauds) avec filtrage de données pour éviter les saccades de mouvement.
* **Couche Matérielle :** ESP32 pilotant des servomoteurs via des signaux PWM (Pulse Width Modulation).

## Points Techniques Clés
* **Traitement en Temps Réel :** Optimisation du flux vidéo pour garantir une latence < 50ms entre le geste et le mouvement.
* **Cinématique Inverse (IK) :** Mapping des coordonnées normalisées de l'IA vers les angles physiques des moteurs (0° - 180°).
* **Architecture Distribuée :** Séparation de la charge de calcul (IA sur CPU/GPU et contrôle sur MCU).

## Compétences Validées
* Développement d'applications hybrides (Python/C++).
* Implémentation de modèles de Deep Learning pré-entraînés (MediaPipe).
* Gestion fine des signaux PWM et de la gigue (jitter) moteur.

---
**Développeur :** Dylan Bassinga  
