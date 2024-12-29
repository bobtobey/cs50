# Blue Gorilla Studio Portfolio Website

#### Video Demo: [Insert Video URL Here]

#### Description:

The **Blue Gorilla Studio Portfolio Website** is a project that I started about midway through the class and kept refining as the class progressed. I crafted this project aimed at showcasing my professional work and skills as a UX Engineer and Frontend Developer. The site is designed with a user-centric focus, emphasizing clean design, intuitive navigation, and functional interactivity. Below is an in-depth explanation of the project, its features, and the technologies employed.

---

### Project Goals:

The primary goal of this portfolio was to capture viewers' attention immediately with compelling hero text and visually engaging content. Each page is designed to balance imagery and text effectively, providing ample white space for visual comfort and reducing cognitive overload. This ensures an enjoyable user experience while allowing my work and skills to shine.

---

### Key Features:

#### 1. **Clean and Engaging Design**:

- Hero text on each page clearly conveys its core purpose.
- Ample use of white space ensures that the layout feels open and uncluttered.
- Eye-catching visuals created using **Photoshop** and **AI tools** enhance the design.

#### 2. **Portfolio Page**:

- Each project block includes:
  - A descriptive image and brief summary.
  - A button to expand and reveal detailed information about the project.
- This feature, implemented using **JavaScript**, ensures that the page remains visually clean while providing detailed content for those interested.

#### 3. **Dynamic User Interactions**:

- Interactive dialog boxes powered by **JavaScript** allow for seamless content expansion and collapse.
- A "Back to Top" button, also utilizing JavaScript, becomes visible as users scroll, enhancing navigation.

#### 4. **Interactive Navigation Bar**:

- A responsive navigation bar was designed using **CSS** to provide visual feedback through hover, focus, and selected states.
- These states keep users informed of their current location and enhance the overall user experience by offering interactive feedback.

---

### Technical Details:

#### HTML Structure:

The site consists of three primary pages:

- **index.html**: Home page with an overview of services and a welcoming introduction.
- **portfolio.html**: A detailed showcase of selected projects with expandable content blocks.
- **contact.html**: A straightforward page with contact options, including email and LinkedIn links.

#### CSS Highlights:

1. **Base Styles (styles.css)**:

   - Established a root font size of `62.5%` (approximately 10px) for easier mental calculations with `rem` and `em` units.
   - Extensive use of **CSS variables** for fonts, colors, and spacing, enabling easy updates and theme changes.
   - A structured **reset style** based on best practices to ensure consistency across browsers.

2. **Custom Styling (bluegorillastudio.css)**:

   - Custom color schemes with **primary**, **complementary**, and **neutral palettes**.
   - Variable-driven designs ensure that changes cascade through the entire project seamlessly.
   - Thoughtful typography and spacing create a professional and inviting look.

3. **Variables File (variables.css)**:

   - Organized definitions for colors, font sizes, and other design properties.
   - Simplified color management and ensured maintainability by centralizing theme definitions.

#### JavaScript Highlights:

1. **JavaScript File (main.js):**

   - Contains all custom scripts to manage interactivity on the website.
   - Implements modular functions for initializing and toggling dialogs, handling alerts and updates, and managing scroll-based features like the "Back to Top" button.

2. **Modular Functions**:
   - `dialogInitializer`: Handles the initialization of dialogs, ensuring seamless interactions.
   - `dialogToggle`: Toggles the visibility of dialogs while maintaining visual cues.
   - `dialogAlertAndUpdate`: Provides dynamic updates for dialogs with visual alerts or updates.

2. **Universal Event Listener**:

   - A centralized listener efficiently manages user interactions, reducing code redundancy.
   - Handles scroll events for showing the "Back to Top" button and click events for dialog toggling.

3. **Back to Top Button**:

   - Scroll-sensitive logic ensures that the button appears only when needed, improving usability.

---

### Design and Development Choices:

1. **CSS Variables for Scalability**:

   - Using variables for font sizes, colors, and other properties ensures quick theme changes and reduces CSS bloat.
   - The centralized variable system provides flexibility for future updates, such as rebranding or theme adjustments.

2. **Color Scheme Design**:

   - A carefully chosen palette with **primary** colors for focal areas and **complementary/neutral** tones for backgrounds and secondary elements.
   - The color scheme was designed to instill a sense of **trust and calm**, enhancing user comfort and engagement.
   - Variables simplify updates to the color scheme, making design iterations efficient.

3. **Collapsible Content in Portfolio Page**:

   - Allows users to focus on high-level summaries while providing detailed content on demand.
   - Balances the need for comprehensive information with a clean, navigable layout.
   - Recognizing that expanding all content on the portfolio page could make it lengthy, I implemented a JavaScript-enabled "Back to Top" button to ensure users can quickly return to the top of the page for better navigation.

---

### Reflection:

This project reflects my skills in UX design, frontend development, and technical problem-solving. By integrating design thinking with modern web technologies, I have created a portfolio that not only showcases my work but also demonstrates my ability to craft user-centric digital experiences. The use of native CSS variables, modular JavaScript, and thoughtful design choices highlights my dedication to both aesthetics and functionality.

---

### Future Enhancements:

1. Add more projects to the portfolio section, showcasing a broader range of skills learned in class.
2. Incorporate a blog section to share insights and articles on UX design and frontend development.
3. Optimize the site further for accessibility and performance.

---

This portfolio represents a collection of my work, my approach to problem-solving, and my passion for creating engaging, efficient, and user-friendly digital experiences.

Note: This document was proofread and spell-checked using ChatGPT and Grammarly to ensure clarity and professionalism.
