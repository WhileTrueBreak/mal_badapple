document.addEventListener('mousemove', () => {
    document.querySelectorAll('.nav-dropdown').forEach(
        e => e.querySelectorAll('.nav-drop')[0].style.display=e.matches(':hover')?'block':'none'
    );
});

const observer = new ResizeObserver(entries => {
    console.log('resize');
    document.querySelectorAll('.menu-image-wrap').forEach(
        e => {
            e.style.height = `${e.offsetWidth}px`;
        }
    );
});

observer.observe(document.querySelector('body'));